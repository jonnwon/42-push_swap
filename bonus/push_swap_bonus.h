/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 00:24:08 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/04 14:39:34 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 42

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

typedef struct s_stacks
{
	t_stack				a;
	t_stack				b;
}						t_stacks;

/*GNL*/
typedef struct s_list
{
	int				fd;
	char			*backup;
	struct s_list	*next;
}				t_list;

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
void		operator(char *op, t_stacks *stacks);

/* sort */
int			is_ascending(t_stack *stack, int len);

/* utils */
void		print_error(t_stacks *stacks);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
void		free_stacks(t_stacks *stacks);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(char *str);

/*gnl*/
char		*get_next_line(int fd);
size_t		ft_strlen2(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr2(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif
