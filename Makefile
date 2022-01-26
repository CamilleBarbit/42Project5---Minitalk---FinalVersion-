# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 11:18:56 by cbarbit           #+#    #+#              #
#    Updated: 2022/01/26 15:13:18 by cbarbit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

C_FILES_CLIENT = client.c \
				client_utils.c\

C_FILES_SERVER = server.c

O_FILES_CLIENT = ${C_FILES_CLIENT:.c=.o}

O_FILES_SERVER = ${C_FILES_SERVER:.c=.o}




${EXEC}: ${O_FILES}
	ar rcs ${EXEC} ${O_FILES}

%.o: %.c
	${CC} ${CFLAGS} -c -g $< -o ${<:.c=.o}

all: ${EXEC}

clean:
	${RM} ${O_FILES_CLIENT} ${RM} ${O_FILES_SERVER}

fclean: clean
	${RM} ${EXEC}

re: fclean all
