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
	static char	c;
	static int	i;

	if (signum == SIGUSR2)
	{
		ft_printf("1");
		c |= 1;
	}
	else
		ft_printf("0");
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		if (c == 0)
			ft_printf("Boi\n");
		c = 0;
		return ;
	}
	else
		c <<= 1;
	i++;
}

int	main(int argc, char* argv[])
{
	struct sigaction	sa;

	if (argc > 1)
		return (0);
	(void) argv;
	sa.sa_handler = print_handler;
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}