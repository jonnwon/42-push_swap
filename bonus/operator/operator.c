/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 05:21:31 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/02 18:13:38 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	is_swap(char *op, t_stacks *stacks)
{
	if (ft_strcmp(op, "sa\n"))
	{
		swap(&stacks->a);
		return (1);
	}
	else if (ft_strcmp(op, "sb\n"))
	{
		swap(&stacks->b);
		return (1);
	}
	else if (ft_strcmp(op, "ss\n"))
	{
		if ((stacks->a.len >= 2) && (stacks->b.len >= 2))
		{
			swap(&stacks->a);
			swap(&stacks->b);
			return (1);
		}
	}
	return (0);
}

int	is_push(char *op, t_stacks *stacks)
{
	if (ft_strcmp(op, "pa\n"))
	{
		push(&stacks->b, &stacks->a);
		return (1);
	}
	else if (ft_strcmp(op, "pb\n"))
	{
		push(&stacks->a, &stacks->b);
		return (1);
	}
	return (0);
}

int	is_rotate(char *op, t_stacks *stacks)
{
	if (ft_strcmp(op, "ra\n"))
	{
		rotate(&stacks->a);
		return (1);
	}
	else if (ft_strcmp(op, "rb\n"))
	{
		rotate(&stacks->b);
		return (1);
	}
	else if (ft_strcmp(op, "rr\n"))
	{
		if ((stacks->a.len >= 2) && (stacks->b.len >= 2))
		{
			rotate(&stacks->a);
			rotate(&stacks->b);
			return (1);
		}
	}
	return (0);
}

int	is_reverse_rotate(char *op, t_stacks *stacks)
{
	if (ft_strcmp(op, "rra\n"))
	{
		reverse_rotate(&stacks->a);
		return (1);
	}
	else if (ft_strcmp(op, "rrb\n"))
	{
		reverse_rotate(&stacks->b);
		return (1);
	}
	else if (ft_strcmp(op, "rrr\n"))
	{
		if ((stacks->a.len >= 2) && (stacks->b.len >= 2))
		{
			reverse_rotate(&stacks->a);
			reverse_rotate(&stacks->b);
		}
		return (1);
	}
	return (0);
}

void	operator(char *op, t_stacks *stacks)
{
	int	tmp;

	tmp = 0;
	tmp += is_swap(op, stacks);
	tmp += is_push(op, stacks);
	tmp += is_rotate(op, stacks);
	tmp += is_reverse_rotate(op, stacks);
	if (!tmp)
		print_error(stacks);
}
