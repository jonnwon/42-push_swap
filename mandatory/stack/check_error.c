/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:05:54 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/01 12:22:15 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_error(t_stacks *stacks)
{
	t_node	*cur;
	t_node	*tmp;
	int		i;
	int		j;

	cur = stacks->a.head;
	i = 0;
	while (i < stacks->a.len)
	{
		j = i + 1;
		tmp = cur->next;
		while (j < stacks->a.len)
		{
			if (cur->value == tmp->value)
				print_error(stacks);
			tmp = tmp->next;
			j++;
		}
		cur = cur->next;
		i++;
	}
}
