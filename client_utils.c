/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:17:37 by cbarbit           #+#    #+#             */
/*   Updated: 2022/01/26 15:18:16 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static int	ft_strlen(char *str) //cette fonction me permet de calculer la taille de mon argv[1]
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
