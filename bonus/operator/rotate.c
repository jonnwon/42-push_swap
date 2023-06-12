/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:41:08 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/02 15:01:42 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	rotate(t_stack *stack)
{
	t_node	*tmp;

	if (stack->len < 2)
		return (0);
	tmp = stack->head;
	stack->head = stack->head->next;
	tmp->next = NULL;
	stack->tail->next = tmp;
	stack->tail = tmp;
	return (1);
}
