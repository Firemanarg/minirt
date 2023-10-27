# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/26 17:44:45 by lsilva-q          #+#    #+#              #
#    Updated: 2023/10/21 23:17:35 by lsilva-q         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ft_list.a

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
AR				= ar rcs

SRCS_DIR		= srcs
OBJS_DIR		= objs

SRC_FILES		= ft_lst_init.c		ft_node_new.c		ft_lst_getindex.c	\
				ft_lst_push_back.c	ft_lst_push_front.c	ft_lst_push.c		\
				ft_lst_pop.c		ft_lst_pop_node.c	ft_lst_getnode.c	\
				ft_lst_dup.c		ft_lst_pop.c		ft_lst_pop_front.c	\
				ft_lst_pop_back.c	ft_node_free.c		ft_lst_clear.c		\
				ft_lst_swap_node.c	ft_lst_toarray.c	ft_lst_push_node.c	\
				ft_lst_get.c		ft_lst_set.c		ft_lst_is_empty.c	\
				ft_lst_func_apply.c	ft_lst_push_ord.c	ft_lst_find.c		\
				ft_lst_first.c		ft_lst_last.c		ft_lst_rmv_null.c	\
				ft_lst_push_front_node.c		ft_lst_push_back_node.c

SRCS			= $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS			= $(addprefix $(OBJS_DIR)/, $(SRC_FILES:%.c=%.o))

HEADER			= ft_list.h

all:			$(NAME)

$(NAME):		$(OBJS)
				$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER)
				mkdir -p $(OBJS_DIR)
				$(CC) $(CFLAGS) -I ./ -c $< -o $@

clean:
				$(RM) $(OBJS)
				$(RM) -rf $(OBJS_DIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
