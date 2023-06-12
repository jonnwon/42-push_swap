/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:28:48 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/02 21:23:14 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node_op	*create_node_op(char *op)
{
	t_node_op	*node;

	node = (t_node_op *)malloc(sizeof(t_node_op));
	if (!node)
		return (NULL);
	node->op = op;
	node->next = NULL;
	return (node);
}

void	lstadd_back_op(t_list *list, char *op)
{
	t_node_op	*node;
	t_node_op	*cur;	

	node = create_node_op(op);
	cur = list->head;
	if (!cur)
	{
		list->head = node;
		list->tail = node;
		list->len++;
		return ;
	}
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = node;
		list->tail = node;
		list->len++;
	}		
}
