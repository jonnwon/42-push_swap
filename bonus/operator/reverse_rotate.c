/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:15:44 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/02 15:01:37 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	reverse_rotate(t_stack *stack)
{
	t_node	*tmp;
	t_node	*cur;

	if (stack->len < 2)
		return (0);
	cur = stack->head;
	while (cur->next->next)
		cur = cur->next;
	tmp = cur->next;
	stack->tail = cur;
	stack->tail->next = NULL;
	tmp->next = stack->head;
	stack->head = tmp;
	return (1);
}
