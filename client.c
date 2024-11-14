/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:43:08 by irkalini          #+#    #+#             */
/*   Updated: 2024/11/14 16:32:12 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_signal_received;

void	check_args(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc != 3)
	{
		ft_printf("Invalid args\n");
		exit(1);
	}
	while (argv[1][++i])
	{
		if (!ft_isdigit(argv[1][i]) || argv[1][0] == '0')
		{
			ft_printf("PID error\n");
			exit(1);
		}
	}
	if (*argv[2] == 0)
	{
		ft_printf("Empty message\n");
		exit(1);
	}
}

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int	i;

	(void)info;
	(void)context;
	g_signal_received = 1;
	if (signum == SIGUSR2)
		i++;
	else if (signum == SIGUSR1)
		ft_printf("Number of bytes received: %d\n", i / 8);
}

int	send_bits(char c, int server_pid)
{
	int	counter;
	int	bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		counter = 0;
		if ((c >> bit_index) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		while (g_signal_received == 0)
		{
			if (counter == 50)
			{
				ft_printf("No signal received\nExit\n");
				exit(1);
			}
			counter++;
			usleep(160);
		}
		g_signal_received = 0;
		bit_index--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sa;
	int					i;

	check_args(argc, argv);
	pid = ft_atoi(argv[1]);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Signal error\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Signal error\n");
	i = 0;
	while (argv[2][i])
		send_bits(argv[2][i++], pid);
	send_bits('\0', pid);
	return (0);
}
