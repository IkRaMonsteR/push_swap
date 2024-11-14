/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irkalini <irkalini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:42:11 by irkalini          #+#    #+#             */
/*   Updated: 2024/11/13 23:25:21 by irkalini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_bits(int signum, char *bin)
{
	if (signum == SIGUSR1)
		*bin = (*bin << 1) | 1;
	else if (signum == SIGUSR2)
		*bin = *bin << 1;
}

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int	pid;
	static int	i;
	static char	c;

	(void)context;
	if (pid == 0)
		pid = info->si_pid;
	receive_bits(signum, &c);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(pid, SIGUSR1);
			pid = 0;
			return ;
		}
		ft_printf("%c", c);
		c = 0;
	}
	kill(pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Signal error\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Signal error\n");
	while (1)
		pause();
	return (0);
}
