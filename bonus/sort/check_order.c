/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:38:01 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/02 15:02:50 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

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
