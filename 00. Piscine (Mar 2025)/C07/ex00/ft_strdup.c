/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:25:48 by bayam             #+#    #+#             */
/*   Updated: 2025/04/06 19:42:59 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	str = (char *) malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*#include <stdio.h>
int	main(void)
{
	char *original = "Hello, world!";
	char *duplicate;

	duplicate = ft_strdup(original);
	if (!duplicate)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	printf("Original: %s\n", original);
	printf("Duplicate: %s\n", duplicate);

	free(duplicate); // Free the allocated memory
	return (0);
}*/