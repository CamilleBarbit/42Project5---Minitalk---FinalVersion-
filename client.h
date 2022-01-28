/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:18:42 by cbarbit           #+#    #+#             */
/*   Updated: 2022/01/28 12:32:17 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <limits.h>
# include "./ft_printf/ft_printf.h"

int		ft_strlen(char *str);
int		ft_atoi(const char *str);
void	char_to_binary(char c, pid_t pid);
void	int_to_binary(int c, pid_t pid);
void	ft_check_parameters(int argc, char **argv);

#endif
