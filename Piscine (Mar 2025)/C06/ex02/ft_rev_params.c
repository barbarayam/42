/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:23:49 by bayam             #+#    #+#             */
/*   Updated: 2025/04/03 21:42:06 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	len;

	if (argc <= 1)
		return (0);
	i = argc - 1;
	while (i > 0)
	{
		len = 0;
		while (argv[i][len] != '\0')
			len++;
		write (1, argv[i], len);
		write (1, "\n", 1);
		i--;
	}
	return (0);
}

/*int	main(int argc, char **argv)
{
	int	i;
	int len;

	if (argc <= 1)
		return (0);
	
	i = argc - 1; // Start from the last argument
	while (i > 0) // Go until i = 1 (skip argv[0])
	{	
		len = 0;
		while(argv[i][len] != '\0')
			len++;
		write(1, argv[i], len);
		write(1, "\n", 1);
		i--;
	}
	return (0);
}*/