/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:00:24 by bayam             #+#    #+#             */
/*   Updated: 2025/04/02 20:19:57 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	j;

	i = 1;
	j = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (i <= power -1)
	{
		nb = nb * j;
		i++;
	}
	return (nb);
}

/*#include <stdio.h>
int main(void)
{
	printf("The answer is: %d\n", ft_iterative_power(-5, 5));
}*/