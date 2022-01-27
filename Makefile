# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 11:18:56 by cbarbit           #+#    #+#              #
#    Updated: 2022/01/27 10:30:26 by camillebarb      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lftprintf -L ./ft_printf
PRINTF = ./ft_printf/libftprintf.a

C_FILES_CLIENT = client.c \
				client_utils.c\

C_FILES_SERVER = server.c

O_FILES_CLIENT = ${C_FILES_CLIENT:.c=.o}

O_FILES_SERVER = ${C_FILES_SERVER:.c=.o}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: server client

server: ${O_FILES_SERVER}
	${LDFLAGS} -o $@ $+

client: ${O_FILES_CLIENT}
	${LDFLAGS} -o $@ $+

all: ${NAME}

clean:
	${RM} ${O_FILES_CLIENT} ${RM} ${O_FILES_SERVER}

fclean: clean
	${RM} ${NAME}

re: fclean all
