# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fharifen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 13:54:57 by fharifen          #+#    #+#              #
#    Updated: 2024/04/22 13:46:41 by fharifen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c lst_config.c check_error.c $(wildcard ./instruction/*.c)
LIBFT = ./libft/libft.a
NAME = push_swap
CC = cc
CFLAGS = -o

${NAME}: ${LIBFT}
	${CC} ${SRCS} -L./libft -lft ${CFLAGS} $@ 

${LIBFT} :
	${MAKE} -C ./libft

clean :
	${MAKE} clean -C ./libft

fclean : clean
	${MAKE} fclean -C ./libft

re : fclean ${NAME}
