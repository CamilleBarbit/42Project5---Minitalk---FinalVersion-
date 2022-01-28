/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:58:53 by cbarbit           #+#    #+#             */
/*   Updated: 2021/12/06 18:15:46 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_nb(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (11);
	if (nb == 0)
		count = 1;
	if (nb < 0)
	{
		nb = nb * -1;
		count = 1;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count += 1;
	}
	return (count);
}

int	ft_count_hexa(unsigned long long int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		count = 1;
	while (nb > 0)
	{
		nb = nb / 16;
		count += 1;
	}
	return (count);
}

int	ft_count_unsigned(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		count = 1;
	while (nb > 0)
	{
		nb = nb / 10;
		count += 1;
	}
	return (count);
}
