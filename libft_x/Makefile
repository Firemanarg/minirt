# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 23:57:47 by lsilva-q          #+#    #+#              #
#    Updated: 2023/09/26 16:02:37 by lsilva-q         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft_x.a

B_SIZE		= 4096

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -D BUFFER_SIZE=$(B_SIZE)
AR			= ar rcs

FTP_DIR		= ft_printf
LFT_DIR		= libft_gnl
OBJS_DIR	= objs

LFT_SRCFLS	= ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c	\
			ft_isprint.c	ft_strlen.c		ft_memset.c		ft_bzero.c		\
			ft_memcpy.c		ft_memmove.c	ft_strlcpy.c	ft_strlcat.c	\
			ft_toupper.c	ft_tolower.c	ft_strchr.c		ft_strrchr.c	\
			ft_strncmp.c	ft_memchr.c		ft_memcmp.c		ft_strnstr.c	\
			ft_atod.c		ft_atoi.c		ft_calloc.c		ft_strdup.c		\
			ft_substr.c		ft_strjoin.c	ft_strtrim.c	ft_itoa.c		\
			ft_strmapi.c	ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	\
			ft_putnbr_fd.c	ft_striteri.c	ft_split.c		ft_strndup.c	\
			ft_strcmp.c			ft_is_whitespace.c		ft_clear_strarr.c	\
			ft_lstnew.c			ft_lstadd_front.c		ft_lstsize.c		\
			ft_lstlast.c		ft_lstadd_back.c		ft_lstdelone.c		\
			ft_lstclear.c		ft_lstiter.c			ft_lstmap.c			\
			get_next_line.c		ft_lstget.c									\
			ft_str_isalpha.c	ft_str_isdigit.c	ft_str_isalnum.c		\
			ft_str_isascii.c	ft_str_isprint.c
FTP_SRCFLS	= ft_printf.c		utils/put_width_chr.c						\
			utils/b_appchr.c	utils/e_appchr.c	utils/ft_ltoa.c			\
			utils/nbr2hex.c		utils/print_chr.c	utils/print_hex.c		\
			utils/print_int.c	utils/print_ptr.c	utils/print_str.c

FTP_SRCS	= $(addprefix $(FTP_DIR)/, $(FTP_SRCFLS))
LFT_SRCS	= $(addprefix $(LFT_DIR)/, $(LFT_SRCFLS))
FTP_OBJS	= $(addprefix $(OBJS_DIR)/, $(FTP_SRCFLS:%.c=%.o))
LFT_OBJS	= $(addprefix $(OBJS_DIR)/, $(LFT_SRCFLS:%.c=%.o))

all:		$(NAME)

$(NAME):	$(FTP_OBJS) $(LFT_OBJS)
			$(AR) $(NAME) $(FTP_OBJS) $(LFT_OBJS)

$(OBJS_DIR)/%.o: $(FTP_DIR)/%.c
			mkdir -p $(OBJS_DIR) $(OBJS_DIR)/utils
			$(CC) $(CFLAGS) -I ./ -c $< -o $@

$(OBJS_DIR)/%.o: $(LFT_DIR)/%.c
			mkdir -p $(OBJS_DIR)
			$(CC) $(CFLAGS) -I ./ -c $< -o $@

clean:
			$(RM) $(FTP_OBJS)
			$(RM) $(LFT_OBJS)
			$(RM) -r $(OBJS_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
