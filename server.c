/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:51:09 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/03/07 14:51:27 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	print_handler(int signum)
{
	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		ft_printf("Hello\n");
	}
}

int	main(int argc, char* argv[])
{
	pid_t	pid;

	(void) argv;
	if (argc > 1)
		return (0);
	pid = getpid();
	ft_printf("%d\n", pid);
	signal(SIGUSR1, print_handler);
	signal(SIGUSR2, print_handler);
	while (1)
		pause();
	return (0);
}