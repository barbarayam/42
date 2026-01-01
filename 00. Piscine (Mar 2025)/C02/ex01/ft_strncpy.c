/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:12:18 by bayam             #+#    #+#             */
/*   Updated: 2025/03/25 16:02:15 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
	char dest[50] = "Dest";
	char src[] = "Source";
	unsigned int n = 20;

	printf("dest before : %s\n", dest);
	ft_strncpy(dest, src,n);
	printf("dest after using ft_strncpy: %s\n", dest);
	strncpy(dest, src, n);
	printf("dest after using the strncpy: %s\n", dest);
	return (0);
}
*/