# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 13:54:57 by fharifen          #+#    #+#              #
#    Updated: 2024/04/22 21:44:14 by fharifen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c $(wildcard ./utils/*.c) $(wildcard ./instruction/*.c)
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
	rm -f ${NAME}

fclean : clean
	${MAKE} fclean -C ./libft

re : fclean ${NAME}
