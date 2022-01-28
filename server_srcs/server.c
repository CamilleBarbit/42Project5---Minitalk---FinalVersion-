/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:19:11 by cbarbit           #+#    #+#             */
/*   Updated: 2022/01/28 14:49:22 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <signal.h>
#include <limits.h>

char   *str = NULL; //je cree une variable globale dans laquelle je stocke tous mes chars.

void    ft_putstr_fd(char *s, int fd) //je n'en aurai pas besoin avec la libft
{
    while (*s)
        write(fd, s++, 1);
}

void    binary_to_int(int signum, int i)
{
    static int  len = 0;

    if (i < 32)
    {
        len = len << 1;
        if (signum == SIGUSR1)
            len = len + 0;
        if (signum == SIGUSR2)
            len = len + 1;
    }
    if (i == 31)
    {
        str = malloc(sizeof(char) * (len + 1));
        if (!str)
            return ;
        // ft_memset(str, 0, len); //je mets des \0 dans ma string pour que ca soit propre.
        len = 0;
    }
}

void    binary_to_char(int signum, int bit, int index, int *i)
{
    static int  c = 0;

    if (bit < 8) //bit correspond aux 8 nbre de bits de chaque char
    {
        c = c << 1;
        if (signum == SIGUSR2)
            c = c + 1;
        if (signum == SIGUSR1)
            c = c + 0;
    }
    if (bit == 7)
    {
        if (str)
        {
            str[index] = c;
            if (c == '\0')
            {
                ft_putstr_fd(str, 1);
                free(str);
                str = NULL;
                *i = -1;
            }
            c = 0;
        }
    }
}

void    handle_signals(int signum, siginfo_t *info, void *useless)
{
    static int  i = 0; //le i correspond au nombre de signaux que je vais recevoir.
    (void)info;
    (void)useless;

    if (i < 32)
        binary_to_int(signum, i); /*je dois envoyer dans une autre fonction qui va modifier le signal recu et stocker les 32 premiers bits dans un int. */
    else
        binary_to_char(signum, (i % 8), ((i - 32) / 8), &i); //l'adresse de i pour le remettre a 0
    i++;
}

int main(void)
{
    struct sigaction    sa;

    printf("The server's PID is: %d\n", getpid()); //j'affiche le PID du server!
    sa.sa_sigaction = handle_signals; //sa_sigaction est defini dans la structure sigaction.
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while(1)//mon programme doit tourner en boucle
        pause();
    return (0);
}
