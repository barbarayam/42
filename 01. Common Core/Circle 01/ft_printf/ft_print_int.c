/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:55:54 by bayam             #+#    #+#             */
/*   Updated: 2025/07/19 22:23:48 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_print_int(int n)
{
	char	*str;
	int		i;
	int		count;

	str = ft_itoa(n);
	if (!str)
		return (0);
	i = 0;
	count = ft_strlen(str);
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	free(str);
	return (count);
}
