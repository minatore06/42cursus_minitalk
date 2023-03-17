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

char	*g_str;

void	str_to_bin_and_send(int pid, char c, int i)
{
	if (c >> i & 1)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
}

void	acknowledge(int signum, siginfo_t *info, void *context)
{
	static int	i = 7;

	(void)context;
	if (i == 0)
	{
		g_str++;
		i = 8;
	}
	i--;
	if (signum == SIGUSR1)
	{
		if (!*g_str)
			kill(info->si_pid, SIGUSR1);
		else
			str_to_bin_and_send(info->si_pid, *g_str, i);
	}
	else if (signum == SIGUSR2)
	{
		ft_printf("Message received\n");
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	sa;
	sigset_t			set;

	sa.sa_sigaction = acknowledge;
	sigemptyset(&set);
	sa.sa_mask = set;
	sa.sa_flags = SA_SIGINFO;
	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	if (!pid && argv[1][0] != '0')
		return (0);
	if (!argv[2])
		return (0);
	g_str = argv[2];
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	str_to_bin_and_send(pid, *g_str, 7);
	while (1)
		pause();
	return (0);
}
