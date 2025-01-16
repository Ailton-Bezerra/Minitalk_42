/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:25:32 by ailbezer          #+#    #+#             */
/*   Updated: 2024/12/06 09:25:37 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_confirm = 0;

void	ft_handle_global(int signum)
{
	if (signum == SIGUSR1)
		g_confirm = 1;
}

void	ft_send_signal(unsigned char letter, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_confirm = 0;
		if ((letter >> bit & 1) == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit++;
		while (!g_confirm)
			;
	}
}

void	ft_end(int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_confirm = 0;
		kill(pid, SIGUSR1);
		bit++;
		while (!g_confirm)
			;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		signal(SIGUSR1, ft_handle_global);
		while (*argv[2])
		{
			ft_send_signal(*argv[2], pid);
			argv[2]++;
		}
		ft_end(pid);
	}
	else
	{
		ft_printf("We only accept gossip in the following format:\n");
		ft_printf("./client <PID> <message>\n");
	}
	return (0);
}
