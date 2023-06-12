/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 05:40:36 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/02 14:15:38 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	operator_cnt_move_to_b(char *op, t_stacks *stacks, int *cnt)
{
	if (ft_strcmp(op, "ra"))
	{
		operator("ra", stacks);
		cnt[RA]++;
	}
	else if (ft_strcmp(op, "pb"))
	{
		operator("pb", stacks);
		cnt[PB]++;
	}
	else if (ft_strcmp(op, "rr"))
	{
		operator("rr", stacks);
		cnt[RA]++;
		cnt[RB]++;
	}
	else if (ft_strcmp(op, "rb"))
	{
		operator("rb", stacks);
		cnt[RB]++;
	}
}

void	move_to_b(t_stacks *stacks, int *pivot, int *cnt, int len)
{
	while (len--)
	{
		if (stacks->a.head->value >= pivot[BIG])
			operator_cnt_move_to_b("ra", stacks, cnt);
		else
		{
			operator_cnt_move_to_b("pb", stacks, cnt);
			if (stacks->b.head->value > pivot[SMALL])
			{
				if (stacks->b.len > 1 && len && \
						stacks->a.head->value >= pivot[BIG])
				{
					operator_cnt_move_to_b("rr", stacks, cnt);
					len--;
				}
				else
					operator_cnt_move_to_b("rb", stacks, cnt);
			}
		}
	}
}

void	sort_chunk(t_stacks *stacks, int len)
{
	t_stack	*a_stack;

	a_stack = &stacks->a;
	if (len < 2)
		return ;
	else if (len == 2 && a_stack->head->value > a_stack->head->next->value)
		operator("sa", stacks);
	else if (len == 3 && !is_ascending(a_stack, 3))
	{
		if (a_stack->head->value > a_stack->head->next->value)
			operator("sa", stacks);
		if (!is_ascending(a_stack, 3))
		{
			operator("ra", stacks);
			operator("sa", stacks);
			operator("rra", stacks);
		}
		if (a_stack->head->value > a_stack->head->next->value)
			operator("sa", stacks);
	}
}

void	sort_a(t_stacks *stacks, int len)
{
	int	pivot[2];
	int	cnt[4];

	if (len <= 3)
	{
		sort_chunk(stacks, len);
		return ;
	}
	init_cnt(cnt);
	set_pivot(pivot, stacks->a, len);
	move_to_b(stacks, pivot, cnt, len);
	rotate_back(stacks, cnt[RA], cnt[RB]);
	sort_a(stacks, cnt[RA]);
	sort_b(stacks, cnt[RB]);
	sort_b(stacks, cnt[PB] - cnt[RB]);
}
