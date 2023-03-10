/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:50:52 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/03/07 14:51:04 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void    acknowledge(int signum)
{
    if (signum == SIGUSR1)
        ft_printf("Message received\n");
}


void    str_to_bin_and_send(int pid, char *str)
{
    int i;

    while (*str)
    {
        i = 8;
        while (i--)
        {
            if (*str >> i & 1){write(1, "1", 1);
                kill(pid, SIGUSR2);}
            else{write(1, "0", 1);
                kill(pid, SIGUSR1);}
            usleep(500);
        }
		//ft_printf("%d", *str);
        write(1, " ", 1);
        str++;
    }
    i = 8;
    while (i--)
    {
        kill(pid, SIGUSR1);
        usleep(300);
    }
}

int main(int argc, char* argv[])
{
    int     pid;
    char    *str;
	struct sigaction	sa;
	sigset_t	set;

	sa.sa_handler = acknowledge;
    sigemptyset(&set);
    sa.sa_mask = set;
    sa.sa_flags = 0;
    if (argc != 3)
        return (0);
    pid = ft_atoi(argv[1]);
    if (!pid && argv[1][0] != '0')
        return (0);
    if (!argv[2])
        return (0);
    str = argv[2];
	sigaction(SIGUSR1, &sa, NULL);
    str_to_bin_and_send(pid, str);
    return (0);
}