/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 06:21:14 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/02 13:41:37 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_pivot(int *pivot, t_stack stack, int len)
{
	int		cnt;
	t_node	*cur;
	t_node	*tmp;
	int		i;
	int		j;

	i = -1;
	cur = stack.head;
	while (++i < len)
	{
		cnt = 0;
		tmp = stack.head;
		j = -1;
		while (++j < len)
		{
			if (cur->value > tmp->value)
				cnt++;
			tmp = tmp->next;
		}
		if (cnt == (len / 3))
			pivot[SMALL] = cur->value;
		else if (cnt == len / 3 * 2)
			pivot[BIG] = cur->value;
		cur = cur->next;
	}
}
