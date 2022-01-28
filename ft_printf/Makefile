# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 12:43:23 by cbarbit           #+#    #+#              #
#    Updated: 2021/12/06 12:08:37 by cbarbit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = libftprintf.a
CC = gcc
RM = rm -rf
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror
SRCS =	ft_checkchar \
		ft_count_nb \
		ft_printandcount_nb \
		ft_printf \
		ft_putchar_count \
		ft_putchar \
		ft_putnbr \
		ft_putstr_count \

C_SRCSFILES = $(addsuffix .c, $(SRCS))
O_SRCSFILES = $(addsuffix .o, $(SRCS))

HDRS = libftprintf.h

${EXEC}: ${O_SRCSFILES}
	${AR} ${EXEC} ${O_SRCSFILES}

.c.o:
	${CC} ${CFLAGS} -c -g $< -o ${<:.c=.o}

all: ${EXEC}

clean:
	${RM} ${O_SRCSFILES}

fclean: clean
	${RM} ${EXEC}

re: fclean all

.PHONY: all clean fclean re
