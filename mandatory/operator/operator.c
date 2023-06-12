/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 05:21:31 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/02 14:29:37 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	is_swap(char *op, t_stacks *stacks)
{
	if (ft_strcmp(op, "sa") && swap(&stacks->a))
		lstadd_back_op(&stacks->list, "sa");
	else if (ft_strcmp(op, "sb") && swap(&stacks->b))
		lstadd_back_op(&stacks->list, "sb");
	else if (ft_strcmp(op, "ss") && (stacks->a.len >= 2) && \
			(stacks->b.len >= 2))
	{
		swap(&stacks->a);
		swap(&stacks->b);
		lstadd_back_op(&stacks->list, "ss");
	}
}

void	is_push(char *op, t_stacks *stacks)
{
	if (ft_strcmp(op, "pa") && push(&stacks->b, &stacks->a))
		lstadd_back_op(&stacks->list, "pa");
	else if (ft_strcmp(op, "pb") && push(&stacks->a, &stacks->b))
		lstadd_back_op(&stacks->list, "pb");
}

void	is_rotate(char *op, t_stacks *stacks)
{
	if (ft_strcmp(op, "ra") && rotate(&stacks->a))
		lstadd_back_op(&stacks->list, "ra");
	else if (ft_strcmp(op, "rb") && rotate(&stacks->b))
		lstadd_back_op(&stacks->list, "rb");
	else if (ft_strcmp(op, "rr") && (stacks->a.len >= 2) && \
				(stacks->b.len >= 2))
	{
		rotate(&stacks->a);
		rotate(&stacks->b);
		lstadd_back_op(&stacks->list, "rr");
	}
}

void	is_reverse_rotate(char *op, t_stacks *stacks)
{
	if (ft_strcmp(op, "rra") && reverse_rotate(&stacks->a))
		lstadd_back_op(&stacks->list, "rra");
	else if (ft_strcmp(op, "rrb") && reverse_rotate(&stacks->b))
		lstadd_back_op(&stacks->list, "rrb");
	else if (ft_strcmp(op, "rrr") && (stacks->a.len >= 2) && \
				(stacks->b.len >= 2))
	{
		reverse_rotate(&stacks->a);
		reverse_rotate(&stacks->b);
		lstadd_back_op(&stacks->list, "rrr");
	}
}

int	operator(char *op, t_stacks *stacks)
{
	is_swap(op, stacks);
	is_push(op, stacks);
	is_rotate(op, stacks);
	is_reverse_rotate(op, stacks);
	return (0);
}
