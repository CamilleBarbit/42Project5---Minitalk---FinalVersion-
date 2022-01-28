/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:31:16 by cbarbit           #+#    #+#             */
/*   Updated: 2021/12/06 18:15:31 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	list_arg;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	va_start(list_arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_checkchar(str[i + 1], list_arg);
			i += 2;
		}
		else
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	va_end(list_arg);
	return (i + count);
}
