/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:24:52 by ailbezer          #+#    #+#             */
/*   Updated: 2024/12/06 09:24:54 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_print_message(int signum, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static int	letter_byte = 0;

	context = NULL;
	if (signum == SIGUSR1)
		letter_byte += 0 << bit;
	else if (signum == SIGUSR2)
		letter_byte += 1 << bit;
	bit++;
	if (bit == 8)
	{	
		if (letter_byte == 0)
			ft_printf("\n");
		else
			ft_printf("%c", letter_byte);
		letter_byte = 0;
		bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	action;

	ft_printf("Welcome, spill the tea!\nPID: %d\n", getpid());
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = ft_print_message;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
}
