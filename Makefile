# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edouvier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 15:46:40 by edouvier          #+#    #+#              #
#    Updated: 2019/07/24 19:55:36 by thabdoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRCS = srcs/ft_putchar.c	\
	   srcs/ft_strdup.c		\
	   srcs/ft_putstr.c		\
	   srcs/ft_strlen.c		\
	   srcs/ft_atoi.c		\
	   srcs/algo.c			\
	   srcs/ft_buf_text.c	\
	   srcs/ft_put_in_tab.c \
	   srcs/main.c			\
	   srcs/ft_split.c		\
	   srcs/ft_put_in_char.c\
	   srcs/check_errors.c	\
	   srcs/ft_strjoin.c 	\

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I./includes

all: $(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
 
re: fclean all

.PHONY: all re clean fclean
