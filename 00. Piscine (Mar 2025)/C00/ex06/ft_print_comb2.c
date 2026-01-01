/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:08:35 by bayam             #+#    #+#             */
/*   Updated: 2025/03/22 21:53:49 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	first;
	int	second;

	first = 0;
	while (first <= 98)
	{
		second = first + 1;
		while (second <= 99)
		{
			ft_putchar((first / 10) + '0');
			ft_putchar((first % 10) + '0');
			ft_putchar(' ');
			ft_putchar((second / 10) + '0');
			ft_putchar((second % 10) + '0');
			if (!(first == 98 && second == 99))
				write(1, ", ", 2);
			second++;
		}
		first++;
	}
}
