/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:19:58 by ancardos          #+#    #+#             */
/*   Updated: 2024/06/05 15:20:00 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "./libft/libft.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int	bit_count = 0;
	static char	character = 0;

	(void)info;
	(void)context;
	if (sig == SIGUSR1)
		character = (character << 1) | 0;
	else if (sig == SIGUSR2)
		character = (character << 1) | 1;
	bit_count++;
	if (bit_count == 8)
	{
		ft_putchar_fd (character, 1);
		bit_count = 0;
		character = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr_fd("Error: Failed to set signal handlers\n", 2);
		return (1);
	}
	ft_putstr_fd ("Server PID: ", 1);
	pid = getpid();
	ft_putnbr_fd (pid, 1);
	ft_putchar_fd ('\n', 1);
	while (1)
	{
		pause();
	}
	return (0);
}
