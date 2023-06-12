/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:40:56 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/02 14:59:19 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	check_str(char *argv)
{
	if (ft_strchr(argv, ' '))
		return (1);
	else
		return (0);
}

void	parsing_n_init_stack(int argc, char **argv, t_stacks *stacks)
{
	t_node	*cur;
	t_node	*node;
	int		i;

	cur = NULL;
	node = NULL;
	i = 1;
	while (i < argc)
	{
		if (!check_str(argv[i]))
		{
			node = create_node(argv[i], cur, stacks);
			if (!stacks->a.head)
				stacks->a.head = node;
			stacks->a.tail = node;
			stacks->a.len++;
			cur = node;
		}
		else
			cur = create_node_string(argv[i], cur, stacks);
		i++;
	}
}
