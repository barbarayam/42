/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:45:20 by bayam             #+#    #+#             */
/*   Updated: 2025/04/03 21:40:06 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	len;

	i = 1;
	if (argc <= 1)
		return (0);
	while (argv[i])
	{
		len = 0;
		while (argv[i][len] != '\0')
			len++;
		write (1, argv[i], len);
		write (1, "\n", 1);
		i++;
	}
	return (0);
}
