/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 16:50:58 by bayam             #+#    #+#             */
/*   Updated: 2025/12/31 16:53:31 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

void	handle_signal(int sig);

void	handle_signal(int sig)
{
	static unsigned char	current_char = 0;
	static int				bit_count = 0;
	unsigned char			mask;

	mask = (1 << (7 - bit_count));
	if (sig == SIGUSR2)
		current_char = current_char | mask;
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == '\0')
			write(1, "\n", 1);
		else
			write(1, &current_char, 1);
		bit_count = 0;
		current_char = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
