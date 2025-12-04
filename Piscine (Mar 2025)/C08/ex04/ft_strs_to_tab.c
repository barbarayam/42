/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:55:49 by bayam             #+#    #+#             */
/*   Updated: 2025/04/09 22:12:54 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strup(char *src)
{
	int		len;
	int		i;
	char	*dup;

	len = ft_strlen(src);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct	s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *result;
	int	i;

	result = malloc( ac + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		result[i].size = ft_strlen(av[i]);
		result[i].str = av[i];
		result[i].copy = ft_strup(av[i]);
		if (!result[i].copy)
		{
			while (i > 0)
			{
				i--;
				free(result[i].copy)
			}
			free(result);
			return (NULL);
		}
		i++;
	}
	result[ac].str = 0;
	result[ac].copy = 0;
	result[ac].size = 0;

	return (result);
}