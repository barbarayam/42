/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 16:51:02 by bayam             #+#    #+#             */
/*   Updated: 2025/12/31 16:26:32 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

void	send_bits(int pid, char c);
int		is_valid_pid_str(char *str);

volatile sig_atomic_t	g_done = 0;

void	ack_handler(int sig)
{
	(void)sig;
	ft_printf("Full message received by server!\n");
	g_done = 1;
}

int	is_valid_pid_str(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	send_bits(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c << bit) & 0x80)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit++;
		usleep(1000);
	}
}

int	main(int ac, char *av[])
{
	int	pid;
	int	i;

	if (ac != 3)
	{
		ft_printf("Error: Incorrect input ./client <PID> <string>\n");
		return (1);
	}
	signal(SIGUSR1, ack_handler);
	pid = ft_atoi(av[1]);
	if (kill(pid, 0) == -1)
	{
		ft_printf("Error: Invalid PID. Process %d does not exist.\n", pid);
		return (1);
	}
	i = 0;
	while (av[2][i] != '\0')
	{
		send_bits(pid, av[2][i]);
		i++;
	}
	send_bits(pid, '\0');
	while (!g_done)
		pause();
	return (0);
}
