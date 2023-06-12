/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:39:03 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/02 15:01:32 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	push(t_stack *from, t_stack *to)
{
	t_node	*tmp;

	if (from->len == 0)
	{
		return (0);
	}
	from->len--;
	to->len++;
	tmp = from->head;
	from->head = from->head->next;
	if (from->len == 0)
		from->tail = NULL;
	if (!to->head)
	{
		tmp->next = NULL;
		to->head = tmp;
		to->tail = tmp;
	}
	else
	{
		tmp->next = to->head;
		to->head = tmp;
	}
	return (1);
}
