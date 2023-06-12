/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:34:24 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/02 13:47:36 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stacks *stacks)
{
	if (stacks->a.head->value > stacks->a.head->next->value)
		operator("sa", stacks);
}

void	sort_four(t_stacks *stacks)
{
	t_node	*cur;
	t_node	*min;

	if (is_ascending(&stacks->a, 4))
		return ;
	cur = stacks->a.head;
	min = cur;
	while (cur)
	{
		if (min->value > cur->value)
			min = cur;
		cur = cur->next;
	}
	cur = stacks->a.head;
	while (cur != min)
	{
		operator("ra", stacks);
		cur = stacks->a.head;
	}
	operator("pb", stacks);
	sort_three(stacks);
	operator("pa", stacks);
}

void	select_min(t_stack *a_stack, int *min)
{
	t_node	*cur;

	min[0] = a_stack->head->value;
	min[1] = a_stack->head->next->value;
	cur = a_stack->head->next->next;
	while (cur)
	{
		if (cur->value < min[0] && cur->value < min[1])
		{
			if (min[0] > min[1])
				min[0] = cur->value;
			else
				min[1] = cur->value;
		}
		else if (cur->value > min[0] && cur->value < min[1])
			min[1] = cur->value;
		else if (cur->value < min[0] && cur->value > min[1])
			min[0] = cur->value;
		cur = cur->next;
	}
}

void	sort_five(t_stacks *stacks)
{
	int		min[2];
	int		i;

	select_min(&stacks->a, min);
	i = 0;
	while (i < 5)
	{
		if (stacks->a.head->value == min[0] || \
				stacks->a.head->value == min[1])
			operator("pb", stacks);
		else
			operator("ra", stacks);
		i++;
	}
	sort_three(stacks);
	if (stacks->b.head->value < stacks->b.head->next->value)
		operator("sb", stacks);
	operator("pa", stacks);
	operator("pa", stacks);
}

void	sort(t_stacks *stacks, int len)
{
	if (len < 2)
		return ;
	else if (len == 2)
		sort_two(stacks);
	else if (len == 3)
		sort_three(stacks);
	else if (len == 4)
		sort_four(stacks);
	else if (len == 5)
		sort_five(stacks);
}
