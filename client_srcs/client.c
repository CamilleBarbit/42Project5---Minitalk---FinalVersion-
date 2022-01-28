/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:19:39 by cbarbit           #+#    #+#             */
/*   Updated: 2022/01/28 15:17:22 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	char_to_binary(char c, pid_t pid)
{
	int	i;
	int	bit;

	i = 7;
	bit = 0;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
		{
			if(kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		usleep(150);
		i--;
	}
	//usleep(80);
}

void	int_to_binary(int c, pid_t pid)
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
			if (kill(pid, SIGUSR1) == -1) //si kill renvoie -1, cela signifie qu'il y a une erreur.
				exit(1);
		}
		usleep(150);
		i--;
	}
	//usleep(80);
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
		if (!(argv[1][i] >= '0' && argv[1][i] <= '9') || (ft_atoi(argv[1]) == 0) || (ft_atoi(argv[1]) > INT_MAX))
		{
			printf("Minitalk cannot work : There is an error with the server's PID!\n");
			exit(1);
		}
		else
			i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	i = 0;
	ft_check_parameters(argc, argv);
	pid = atoi(argv[1]);
	if (argc == 3)
	{
		int_to_binary(ft_strlen(argv[2]), pid); //je lui envoie la taille de mon argv[2]
		while (argv[2][i]) // soit while (argv[2][i] != '\0')
		{
			char_to_binary(argv[2][i], pid); //-> cette fonction prend chaque char de argv[2] et le PID du server (soit argv[1])
			i++;
		}
		char_to_binary('\0', pid); //j'apelle la fonction une derniere fois pour envoyer le '\0'
	}
	return (0);
}
