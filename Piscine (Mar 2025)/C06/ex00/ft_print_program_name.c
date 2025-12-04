/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:39:20 by bayam             #+#    #+#             */
/*   Updated: 2025/04/03 21:41:09 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	if (argc > 0)
	{
		while (argv[0][len] != '\0')
		{
			len++;
		}
		write(1, argv[0], len);
		write(1, "\n", 1);
	}
	return (0);
}
