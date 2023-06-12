/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stick_operation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:36:01 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/02 18:39:18 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_stick_two_operation(t_node_op *cur, char *op1, char *op2)
{
	if (cur->next && ft_strcmp(cur->op, op1) && \
		ft_strcmp(cur->next->op, op2))
		return (1);
	else if (cur->next && ft_strcmp(cur->op, op2) && \
			ft_strcmp(cur->next->op, op1))
		return (1);
	return (0);
}

int	is_stick_next_two_operation(t_node_op *cur, char *op1, char *op2)
{
	if (cur->next && cur->next->next && \
			ft_strcmp(cur->next->op, op1) && \
			ft_strcmp(cur->next->next->op, op2))
		return (1);
	else if (cur->next && cur->next->next && \
			ft_strcmp(cur->next->op, op2) && \
			ft_strcmp(cur->next->next->op, op1))
		return (1);
	return (0);
}
