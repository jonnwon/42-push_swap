/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:23:46 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/02 17:39:55 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stacks_value_null(t_stacks *stacks)
{
	stacks->a.head = NULL;
	stacks->a.tail = NULL;
	stacks->a.len = 0;
	stacks->b.head = NULL;
	stacks->b.tail = NULL;
	stacks->b.len = 0;
	stacks->list.head = NULL;
	stacks->list.tail = NULL;
	stacks->list.len = 0;
}

void	sort_len(t_stacks *stacks, int len)
{
	if (len == 2)
		sort(stacks, len);
	else if (len == 3)
		sort(stacks, len);
	else if (len == 4)
		sort(stacks, len);
	else if (len == 5)
		sort(stacks, len);
	else
		sort_a(stacks, len);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			tmp;

	if (argc < 2)
		return (0);
	stacks_value_null(&stacks);
	parsing_n_init_stack(argc, argv, &stacks);
	check_error(&stacks);
	if (is_ascending(&stacks.a, stacks.a.len))
	{
		free_stacks(&stacks);
		return (0);
	}
	sort_len(&stacks, stacks.a.len);
	tmp = stacks.list.len + 1;
	while (tmp != stacks.list.len)
	{
		tmp = stacks.list.len;
		optimization(&stacks);
	}
	print_op(&stacks.list);
	free_stacks(&stacks);
	free_list(&stacks.list);
	return (0);
}
