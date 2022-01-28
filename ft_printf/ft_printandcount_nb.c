/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printandcount_nb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:04:29 by cbarbit           #+#    #+#             */
/*   Updated: 2021/12/06 18:15:39 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printandcount_nb(int nb)
{
	ft_putnbr(nb);
	return (ft_count_nb(nb) - 2);
}

int	ft_printandcount_bigx(unsigned int nb)
{
	ft_putnbr_hexa(nb, "0123456789ABCDEF");
	return (ft_count_hexa(nb) - 2);
}

int	ft_printandcount_ptr(unsigned long long int nb)
{
	ft_putnbr_ptr(nb, "0123456789abcdef");
	return (ft_count_hexa(nb));
}

int	ft_printandcount_x(unsigned int nb)
{
	ft_putnbr_hexa(nb, "0123456789abcdef");
	return (ft_count_hexa(nb) - 2);
}

int	ft_printandcount_unsigned(unsigned int nb)
{
	ft_putnbr_unsigned(nb);
	return (ft_count_unsigned(nb) - 2);
}
