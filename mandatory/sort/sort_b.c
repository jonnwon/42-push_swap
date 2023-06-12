/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:43:48 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/02 14:22:39 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	operator_cnt_move_to_a(char *op, t_stacks *stacks, int *cnt)
{
	if (ft_strcmp(op, "rb"))
	{
		operator("rb", stacks);
		cnt[RB]++;
	}
	else if (ft_strcmp(op, "pa"))
	{
		operator("pa", stacks);
		cnt[PA]++;
	}
	else if (ft_strcmp(op, "rr"))
	{
		operator("rr", stacks);
		cnt[RA]++;
		cnt[RB]++;
	}
	else if (ft_strcmp(op, "ra"))
	{
		operator("ra", stacks);
		cnt[RA]++;
	}
}

void	move_to_a(t_stacks *stacks, int *pivot, int *cnt, int len)
{
	while (len--)
	{
		if (stacks->b.head->value <= pivot[SMALL])
			operator_cnt_move_to_a("rb", stacks, cnt);
		else
		{
			operator_cnt_move_to_a("pa", stacks, cnt);
			if (stacks->a.head->value < pivot[BIG])
			{
				if (len && stacks->b.head->value <= pivot[SMALL])
				{
					operator_cnt_move_to_a("rr", stacks, cnt);
					len--;
				}
				else
					operator_cnt_move_to_a("ra", stacks, cnt);
			}	
		}
	}
}

void	sort_b(t_stacks *stacks, int len)
{
	int	pivot[2];
	int	cnt[4];
	int	tmp;

	init_cnt(cnt);
	if (len <= 3)
	{
		tmp = len;
		while (len)
		{
			operator("pa", stacks);
			len--;
		}
		sort_a(stacks, tmp);
		return ;
	}
	set_pivot(pivot, stacks->b, len);
	move_to_a(stacks, pivot, cnt, len);
	sort_a(stacks, cnt[PA] - cnt[RA]);
	rotate_back(stacks, cnt[RA], cnt[RB]);
	sort_a(stacks, cnt[RA]);
	sort_b(stacks, cnt[RB]);
}
