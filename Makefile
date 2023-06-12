# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 12:30:01 by jonchoi           #+#    #+#              #
#    Updated: 2023/01/04 14:37:17 by jonchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= push_swap
NAME_BONUS				= checker

CC						= cc
CFLAGS					= -Wall -Wextra -Werror
AR						= ar rcs
RM						= rm -f

MAND_DIR				= ./mandatory/
BONUS_DIR				= ./bonus/

STACK_DIR				=	stack/
STACK_SRC				=	init_stack.c create_node.c create_node_string.c\
							check_error.c
STACK_SRC_BONUS			=	check_error.c create_node_string.c create_node.c\
							 init_stack.c

OPERATOR_DIR			=	operator/
OPERATOR_SRC			=	push.c rotate.c reverse_rotate.c swap.c\
							operator.c optimization.c is_stick_operation.c
OPERATOR_SRC_BONUS		=	operator.c reverse_rotate.c swap.c push.c rotate.c

SORT_DIR				=	sort/
SORT_SRC				=	sort.c check_order.c sort_a.c pivot.c sort_b.c\
							sort_three.c rotate_back.c init_cnt.c
SORT_SRC_BONUS			=	check_order.c

UTILS_DIR				=	utils/
UTILS_SRC				=	ft_split.c print_error.c ft_strlen.c ft_strchr.c\
							ft_strcmp.c ft_putstr.c create_node_op.c\
							print_op.c free_stacks.c
UTILS_SRC_BONUS			=	free_stacks.c ft_split.c ft_strcmp.c print_error.c\
							ft_putstr.c ft_strchr.c ft_strlen.c

GNL_DIR					=	get_next_line/
GNL_SRC_BONUS			=	get_next_line_bonus.c get_next_line_utils_bonus.c

SRC						=	main.c\
							$(addprefix $(STACK_DIR), $(STACK_SRC))\
							$(addprefix $(UTILS_DIR), $(UTILS_SRC))\
							$(addprefix $(OPERATOR_DIR), $(OPERATOR_SRC))\
							$(addprefix $(SORT_DIR), $(SORT_SRC))
SRC_BONUS				=	main.c\
							$(addprefix $(STACK_DIR), $(STACK_SRC_BONUS))\
							$(addprefix $(UTILS_DIR), $(UTILS_SRC_BONUS))\
							$(addprefix $(OPERATOR_DIR), $(OPERATOR_SRC_BONUS))\
							$(addprefix $(SORT_DIR), $(SORT_SRC_BONUS))\
							$(addprefix $(GNL_DIR), $(GNL_SRC_BONUS))\


SRCS					=	$(addprefix $(MAND_DIR), $(SRC))
SRCS_BONUS				=	$(addprefix $(BONUS_DIR), $(SRC_BONUS))

OBJS					=	$(SRCS:.c=.o)
OBJS_BONUS				=	$(SRCS_BONUS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_BONUS) : $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $@ $^

bonus : $(NAME_BONUS)

clean :
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re :
	make fclean
	make all

.PHONY	:	all clean fclean re bonus
