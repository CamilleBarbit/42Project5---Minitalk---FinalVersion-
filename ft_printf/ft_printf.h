/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:26:26 by cbarbit           #+#    #+#             */
/*   Updated: 2021/12/06 18:34:43 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_checkchar(char a, va_list list_arg);
int		ft_count_nb(int nb);
int		ft_count_hexa(unsigned long long int nb);
int		ft_count_unsigned(unsigned int nb);
int		ft_printandcount_nb(int nb);
int		ft_printandcount_bigx(unsigned int nb);
int		ft_printandcount_ptr(unsigned long long int nb);
int		ft_printandcount_unsigned(unsigned int nb);
int		ft_printandcount_x(unsigned int nb);
int		ft_printf(const char *str, ...);
int		ft_putchar_count(char c);
void	ft_putchar(char c);
void	ft_putnbr_ptr(unsigned long long int nb, char *base);
void	ft_putnbr_hexa(unsigned int nb, char *base);
void	ft_putnbr(int nb);
void	ft_putnbr_unsigned(unsigned int nb);
int		ft_putstr_count(char *str);

#endif
