/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:46:41 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/02 13:55:16 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	operator_sa_rra(char *sa, char *rra, t_stacks *stacks)
{
	operator(sa, stacks);
	operator(rra, stacks);
}

void	operator_sa_ra(char *sa, char *ra, t_stacks *stacks)
{
	operator(sa, stacks);
	operator(ra, stacks);
}

void	sort_three(t_stacks *stacks)
{
	if (is_ascending(&stacks->a, 3))
		return ;
	if (is_descending(&stacks->a, 3))
	{
		operator_sa_rra("sa", "rra", stacks);
		return ;
	}
	if (stacks->a.head->value > stacks->a.head->next->value)
	{
		if (stacks->a.head->value < stacks->a.tail->value)
			operator("sa", stacks);
		else
			operator("ra", stacks);
		return ;
	}
	else
	{
		if (stacks->a.head->value < stacks->a.tail->value)
		{
			operator_sa_ra("sa", "ra", stacks);
			return ;
		}
		operator("rra", stacks);
		return ;
	}
}
