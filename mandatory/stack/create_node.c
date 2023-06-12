/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:22:31 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/03 18:10:28 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	is_digit(char *str, t_stacks *stacks)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (!(str[j] >= '0' && str[j] <= '9'))
			print_error(stacks);
		j++;
	}
}

long long	ft_atoll(char *str, t_stacks *stacks)
{
	long long	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!str[i])
		print_error(stacks);
	is_digit(&str[i], stacks);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (sign * num);
}

void	init_address(t_node *node, t_node *cur)
{
	if (!cur)
	{
		node->next = NULL;
		return ;
	}
	node->next = NULL;
	cur->next = node;
}

t_node	*create_node(char *num, t_node *cur, t_stacks *stacks)
{
	long long	value;
	t_node		*node;

	value = ft_atoll(num, stacks);
	if (value > 2147483647 || value < -2147483648)
		print_error(stacks);
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	init_address(node, cur);
	return (node);
}
