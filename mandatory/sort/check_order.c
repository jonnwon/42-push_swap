/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:38:01 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/02 13:38:37 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_ascending(t_stack *stack, int len)
{
	t_node	*tmp;

	tmp = stack->head;
	len--;
	while (len)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
		len--;
	}
	return (1);
}

int	is_descending(t_stack *stack, int len)
{
	t_node	*tmp;

	tmp = stack->head;
	len--;
	while (len)
	{
		if (tmp->value < tmp->next->value)
			return (0);
		tmp = tmp->next;
		len--;
	}
	return (1);
}
