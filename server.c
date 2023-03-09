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

void	print_handler(int signum, siginfo_t *info, void *context)
{
	static char	c;
	static int	i;

	(void)context;
	i++;
	if (signum == SIGUSR2)
		c |= 1;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		if (c == 0)
			kill(info->si_pid, SIGUSR1);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(int argc, char* argv[])
{
	struct sigaction	sa;

	if (argc > 1)
		return (0);
	(void) argv;
	sa.sa_sigaction = print_handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}