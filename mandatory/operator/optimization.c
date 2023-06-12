/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:34:45 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/02 18:38:02 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	delete_one_and_change(t_node_op *cur, char *op, t_stacks *stacks)
{
	t_node_op	*tmp;

	cur->op = op;
	tmp = cur->next;
	cur->next = cur->next->next;
	free(tmp);
	stacks->list.len--;
}

void	check_delete_one(t_node_op *cur, t_stacks *stacks)
{
	if (is_stick_two_operation(cur, "sa", "sb"))
		delete_one_and_change(cur, "ss", stacks);
	else if (is_stick_two_operation(cur, "ra", "rb"))
		delete_one_and_change(cur, "rr", stacks);
	else if (is_stick_two_operation(cur, "rra", "rrb"))
		delete_one_and_change(cur, "rrr", stacks);
	else if (is_stick_two_operation(cur, "rrr", "rb"))
		delete_one_and_change(cur, "rra", stacks);
	else if (is_stick_two_operation(cur, "rrr", "ra"))
		delete_one_and_change(cur, "rrb", stacks);
	else if (is_stick_two_operation(cur, "rr", "rrb"))
		delete_one_and_change(cur, "ra", stacks);
	else if (is_stick_two_operation(cur, "rr", "rra"))
		delete_one_and_change(cur, "rb", stacks);
}

void	delete_two(t_node_op *cur, t_stacks *stacks)
{
	t_node_op	*tmp;

	tmp = cur->next;
	if (cur->next->next->next)
		cur->next = cur->next->next->next;
	else
		cur->next = NULL;
	free(tmp->next);
	free(tmp);
	stacks->list.len--;
	stacks->list.len--;
}

void	check_delete_two(t_node_op *cur, t_stacks *stacks)
{
	if (is_stick_next_two_operation(cur, "sa", "sa"))
		delete_two(cur, stacks);
	else if (is_stick_next_two_operation(cur, "sb", "sb"))
		delete_two(cur, stacks);
	else if (is_stick_next_two_operation(cur, "pa", "pb"))
		delete_two(cur, stacks);
	else if (is_stick_next_two_operation(cur, "ra", "rra"))
		delete_two(cur, stacks);
	else if (is_stick_next_two_operation(cur, "rb", "rrb"))
		delete_two(cur, stacks);
	else if (is_stick_next_two_operation(cur, "rr", "rrr"))
		delete_two(cur, stacks);
}

void	optimization(t_stacks *stacks)
{
	t_node_op	*cur;

	cur = stacks->list.head;
	while (cur)
	{
		check_delete_one(cur, stacks);
		check_delete_two(cur, stacks);
		cur = cur->next;
	}
}
