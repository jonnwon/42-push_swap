/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:40:12 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/02 13:36:36 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*create_node_string(char *argv, t_node *cur, t_stacks *stacks)
{
	char	**arr;
	int		i;
	t_node	*node;

	node = NULL;
	arr = ft_split(argv, ' ');
	if (!arr[0])
	{
		free(arr);
		print_error(stacks);
	}
	i = -1;
	while (arr[++i])
	{
		node = create_node(arr[i], cur, stacks);
		if (!stacks->a.head)
			stacks->a.head = node;
		stacks->a.tail = node;
		stacks->a.len++;
		cur = node;
	}
	while (--i >= 0)
		free(arr[i]);
	free(arr);
	return (node);
}
