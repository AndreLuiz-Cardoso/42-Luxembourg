/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:08:35 by ancardos          #+#    #+#             */
/*   Updated: 2024/05/30 17:08:36 by ancardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

void	sigint_handler(int signum __attribute__((unused)))
{
}

void	send_char(pid_t server_pid, char c)
{
	int	i;
	int	result;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
		{
			result = kill(server_pid, SIGUSR2);
		}
		else
		{
			result = kill(server_pid, SIGUSR1);
		}
		if (result == -1)
		{
			ft_putstr_fd("Error: kill failed\n", 2);
			perror("kill");
			exit(EXIT_FAILURE);
		}
		usleep(100);
		i--;
	}
}

void	send_message(pid_t server_pid, char *message)
{
	while (*message)
	{
		send_char(server_pid, *message);
		message++;
	}
	send_char(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	signal(SIGINT, sigint_handler);
	if (argc != 3)
	{
		ft_putstr_fd("Error: Incorrect arguments!\n", 2);
		ft_putstr_fd("Try: <PID> \"<MESSAGE>\"\n", 2);
		exit(1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_putstr_fd("Error: Invalid PID\n", 2);
		exit(1);
	}
	ft_putstr_fd("Sending message...\n", 1);
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(server_pid, 1);
	ft_putchar_fd('\n', 1);
	send_message(server_pid, argv[2]);
	ft_putstr_fd("Message sent!\n", 1);
	return (0);
}
