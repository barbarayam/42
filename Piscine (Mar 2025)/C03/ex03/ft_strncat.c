/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 21:43:24 by bayam             #+#    #+#             */
/*   Updated: 2025/03/26 22:10:00 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (j < nb && src[j] != '\0')
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

int main()
{
    // Test 1: Normal concatenation with nb < length of src
    char dest1[50] = "Hello, ";
    char src1[] = "World!";
    printf("Test 1 - Before: %s\n", dest1);
    ft_strncat(dest1, src1, 3); // Append only first 3 characters of src
    printf("Test 1 - After: %s\n", dest1); // Expected: "Hello, Wor"

    // Test 2: Normal concatenation with nb > length of src
    char dest2[50] = "Hello, ";
    char src2[] = "World!";
    printf("Test 2 - Before: %s\n", dest2);
    ft_strncat(dest2, src2, 10); 
    printf("Test 2 - After: %s\n", dest2); // Expected: "Hello, World!"

    // Test 3: Concatenation with nb = 0
    char dest3[50] = "Hello, ";
    char src3[] = "World!";
    printf("Test 3 - Before: %s\n", dest3);
    ft_strncat(dest3, src3, 0); // Append nothing (nb = 0)
    printf("Test 3 - After: %s\n", dest3); // Expected: "Hello, "

    return 0;
}
*/