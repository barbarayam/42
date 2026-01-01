/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 21:27:34 by bayam             #+#    #+#             */
/*   Updated: 2025/03/26 22:06:54 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int main() 
{
    // Test 1: Normal concatenation
    char dest1[50] = "Hello, ";
    char src1[] = "World!";
    ft_strcat(dest1, src1);
    printf("Test 1: %s\n", dest1); // Expected: "Hello, World!"

    // Test 2: Empty source string
    char dest2[50] = "Hello";
    char src2[] = "";
    ft_strcat(dest2, src2);
    printf("Test 2: %s\n", dest2); // Expected: "Hello"

    // Test 3: Empty destination string
    char dest3[50] = "";
    char src3[] = "World!";
    ft_strcat(dest3, src3);
    printf("Test 3: %s\n", dest3); // Expected: "World!"

	return 0;
}
*/