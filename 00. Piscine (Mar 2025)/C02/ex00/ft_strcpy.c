/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:44:26 by bayam             #+#    #+#             */
/*   Updated: 2025/03/25 15:57:30 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char dest[] = "Dest";
	char src[] = "Source";

	printf("dest before : %s\n", dest);
	ft_strcpy(dest, src);
	printf("dest after : %s\n", dest);

	strcpy(dest, src);
	printf("dest after using the strcpy: %s\n", dest);
}
*/