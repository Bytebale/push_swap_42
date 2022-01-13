# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/25 21:36:53 by lshonta           #+#    #+#              #
#    Updated: 2022/01/12 16:19:01 by lshonta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = push_swwap.h
MAKEB = make bonus

SRCS = source/push_swap.c\
		source/ft_simple.c\
		source/ft_radix.c\
		includes/push_rules.c\
		includes/reverse_rules.c\
		includes/rotate_rules.c\
		includes/swap_rules.c\
		includes/ft_utils.c\
		includes/ft_put_index.c\
		includes/ft_check.c
		
OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: ${NAME} 

${NAME}: ${OBJS}
	@$(MAKEB) -C ./libft
	${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

clean: 
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re