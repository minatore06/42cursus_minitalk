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

int main(int argc, char* argv[])
{
    int     pid;
    char    *str;

    if (argc != 3)
        return (0);
    pid = ft_atoi(argv[1]);
    if (!pid && argv[1][0] != '0')
        return (0);
    str = argv[2];
    if (!str)
        return (0);
    kill(pid, SIGUSR1);
    return (0);
}