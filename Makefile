# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/28 12:38:50 by cbarbit           #+#    #+#              #
#    Updated: 2022/01/28 12:39:29 by cbarbit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -lftprintf -L ./ft_printf

PATH = ./ft_printf/libftprintf.a

FTPRINTF = libftprintf.a

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
