/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:00:49 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/02 21:23:32 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define SMALL	1
# define BIG	0

# define RA 0
# define PA 1
# define RB 2
# define PB 3

typedef struct s_node
{
	int					value;
	struct s_node		*next;
}						t_node;

typedef struct s_stack
{
	t_node				*head;
	t_node				*tail;
	int					len;
}						t_stack;

typedef struct s_node_op
{
	char				*op;
	struct s_node_op	*next;
}						t_node_op;

typedef struct s_list
{
	t_node_op		*head;
	t_node_op		*tail;
	int				len;
}					t_list;

typedef struct s_stacks
{
	t_stack				a;
	t_stack				b;
	t_list				list;
}						t_stacks;

/* stack */
t_node		*create_node(char *num, t_node *cur, t_stacks *stacks);
t_node		*create_node_string(char *argv, t_node *cur, t_stacks *stacks);
void		check_error(t_stacks *stacks);
void		parsing_n_init_stack(int argc, char **argv, t_stacks *stacks);

/* operator */
int			swap(t_stack *stack);
int			push(t_stack *from, t_stack *to);
int			rotate(t_stack *stack);
int			reverse_rotate(t_stack *stack);
int			operator(char *op, t_stacks *stacks);
void		optimization(t_stacks *stacks);
int			is_stick_two_operation(t_node_op *cur, char *op1, char *op2);
int			is_stick_next_two_operation(t_node_op *cur, char *op1, char *op2);

/* sort */
int			is_ascending(t_stack *stack, int len);
int			is_descending(t_stack *stack, int len);
void		sort(t_stacks *stacks, int len);
void		sort_three(t_stacks *stacks);

void		set_pivot(int *pivot, t_stack stack, int len);
void		sort_a(t_stacks *stacks, int len);
void		sort_b(t_stacks *stacks, int len);
void		init_cnt(int *cnt);
void		rotate_back(t_stacks *stacks, int ra_cnt, int rb_cnt);

/* utils */
char		**ft_split(char const *s, char c);
void		print_error(t_stacks *stacks);
size_t		ft_strlen(char *str);
char		*ft_strchr(const char *s, int c);
void		ft_putstr(char *str);
int			ft_strcmp(char *s1, char *s2);
void		print_op(t_list *list);
void		free_stacks(t_stacks *stacks);
void		free_list(t_list *list);

/* create_node_op.c */
void		lstadd_back_op(t_list *list, char *op);
t_node_op	*create_node_op(char *op);

#endif
