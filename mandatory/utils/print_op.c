/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:37:09 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/02 14:36:24 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_op(t_list	*list)
{
	t_node_op	*cur;
	char		*str;

	cur = list->head;
	while (cur)
	{
		str = cur->op;
		ft_putstr(str);
		ft_putstr("\n");
		cur = cur->next;
	}
}
