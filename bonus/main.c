/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 00:14:48 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/03 17:50:17 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	stacks_value_null(t_stacks *stacks)
{
	stacks->a.head = NULL;
	stacks->a.tail = NULL;
	stacks->a.len = 0;
	stacks->b.head = NULL;
	stacks->b.tail = NULL;
	stacks->b.len = 0;
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		*op;

	if (argc < 2)
		return (0);
	stacks_value_null(&stacks);
	parsing_n_init_stack(argc, argv, &stacks);
	check_error(&stacks);
	while (1)
	{
		op = get_next_line(0);
		if (!op)
			break ;
		operator(op, &stacks);
	}
	if (is_ascending(&stacks.a, stacks.a.len) && stacks.b.len == 0)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	return (0);
}
