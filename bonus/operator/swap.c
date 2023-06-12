/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:36:14 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/02 15:01:45 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	swap(t_stack *stack)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (stack->len < 2)
		return (0);
	tmp1 = stack->head;
	tmp2 = stack->head->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	stack->head = tmp2;
	stack->head->next = tmp1;
	if (stack->len == 2)
		stack->tail = tmp1;
	return (1);
}
