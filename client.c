/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:19:39 by cbarbit           #+#    #+#             */
/*   Updated: 2022/01/26 14:35:13 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//je definis 0 quand tout va bien et 1 quand il y a une erreur

// #include "minitalk.h"
//#include "libft.h"
//#include "ft_printf.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <signal.h>
#include <stdio.h>

int ft_atoi(const char *str) //pas besoin une fois link avec la libf
{
    int i;
    int nbr;
    int sign;

    i = 0;
    nbr = 0;
    sign = 1;
    while (str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr * sign);
}

static int	ft_strlen(char *str) //cette fonction me permet de calculer la taille de mon argv[1]
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	char_to_binary(char c, pid_t pid)
{
	int	i;
	int	bit;
	int	ret;

	i = 7;
	bit = 0;
	ret = 0;
	while (i >= 0)
	{
		bit = (c >> i) & 1; //cela va decaler de i rangs la version en binaire de ma lettre c.
		if (bit == 1)
			ret = kill(pid, SIGUSR2);
		else
			ret = kill(pid, SIGUSR1);
		{
			if (ret == -1)
			{
				write(1, "Signal Error\n", 13);
				exit(1);
			}
		}
		usleep(40);
		i--;
	}
	usleep(80);
}


void	int_to_binary(int c, pid_t pid) //testons en envoyant la longueur de ma chaine de caractere, soit de mon argv[2].
{
	int		i;
	int		bit;

	i = 31;
	bit = 0;
	while (i >= 0)
	{
		bit = (c >> i) & 1; //cela va decaler de i rangs la version en binaire de ma lettre c.
		if (bit == 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1) //si kill renvoie -1, cela signifie qu'il y a une erreur
				exit(1);
		}
		usleep(20);
		i--;
	}
	usleep(100);
}

void	ft_check_parameters(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		printf("Minitalk cannot work: Wrong number of arguments!\n");
		exit(1);
	}
	if (argv[1][0] == '\0')
	{
		printf("Minitalk cannot work: Where is the server's PID?\n");
		exit(1);
	}
	while (argv[1][i])
	{
		if (!(argv[1][i] >= '0' && argv[1][i] <= '9' ) || (ft_atoi(argv[1]) == 0))
		{
			printf("Minitalk cannot work : There is an error with the server's PID!\n");
			exit(1);
		}
		else
			i++;
	}
}

//Que se passe-t-il si le PID rentré n'est pas celui du sever?

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	ft_check_parameters(argc, argv);
	if (argc == 3)
	{
		int_to_binary(ft_strlen(argv[2]), atoi(argv[1])); //je lui envoie la taille de mon argv[2]
		while (argv[2][i]) // soit while (argv[2][i] != '\0')
		{
			char_to_binary(argv[2][i], atoi(argv[1])); //-> cette fonction prend chaque char de argv[2] et le PID du server (soit argv[1])
			i++;
		}
		char_to_binary('\0', atoi(argv[1])); //j'apelle la fonction une derniere fois pour envoyer le '\0'
	}
	return (0);
}
