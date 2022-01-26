# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 11:18:56 by cbarbit           #+#    #+#              #
#    Updated: 2022/01/26 11:18:57 by cbarbit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


EXEC = minitalk.a
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

C_FILES = client.c server.c client_utils.c

O_FILES = ${C_FILES:.c=.o}

${EXEC}: ${O_FILES}
	ar rcs ${EXEC} ${O_FILES}

.c.o:
	${CC} ${CFLAGS} -c -g $< -o ${<:.c=.o}

all: ${EXEC}

clean:
	${RM} ${O_FILES}

fclean: clean
	${RM} ${EXEC}

re: fclean all
