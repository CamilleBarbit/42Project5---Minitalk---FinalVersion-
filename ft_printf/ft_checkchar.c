/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:53:29 by cbarbit           #+#    #+#             */
/*   Updated: 2021/12/06 18:15:50 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkchar(char a, va_list list_arg)
{
	int	count;

	count = 0;
	if (a == 's')
		count = ft_putstr_count(va_arg(list_arg, char *));
	else if (a == 'd' || a == 'i')
		count = ft_printandcount_nb(va_arg(list_arg, int));
	else if (a == 'c')
		count = ft_putchar_count(va_arg(list_arg, int));
	else if (a == 'u')
		count = ft_printandcount_unsigned(va_arg(list_arg, unsigned int));
	else if (a == 'x')
		count = ft_printandcount_x(va_arg(list_arg, unsigned int));
	else if (a == 'X')
		count = ft_printandcount_bigx(va_arg(list_arg, unsigned int));
	else if (a == 'p')
	{
		count = ft_putchar_count('0');
		count = ft_putchar_count('x');
		count = ft_printandcount_ptr(va_arg(list_arg, unsigned long long int));
	}
	else if (a == '%')
		count = ft_putchar_count('%');
	return (count);
}
