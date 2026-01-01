/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:55:27 by bayam             #+#    #+#             */
/*   Updated: 2025/06/03 20:20:41 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	p = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == ((unsigned char)c))
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char arr1[] = "Hello, World!";
    char arr2[] = {0, 1, 2, 3, 4, 5};
    char arr3[] = "abcdefg";

    // Test 1: Character is present
    char *res1 = ft_memchr(arr1, 'W', sizeof(arr1));
    if (res1)
        printf("Test 1: Found 'W' at index %ld\n", res1 - arr1);
    else
        printf("Test 1: 'W' not found\n");

    // Test 2: Character is not present
    char *res2 = ft_memchr(arr1, 'z', sizeof(arr1));
    if (res2)
        printf("Test 2: Found 'z' at index %ld\n", res2 - arr1);
    else
        printf("Test 2: 'z' not found\n");

    // Test 3: Search for null terminator
    char *res3 = ft_memchr(arr1, '\0', sizeof(arr1));
    if (res3)
        printf("Test 3: Found '\\0' at index %ld\n", res3 - arr1);
    else
        printf("Test 3: '\\0' not found\n");

    // Test 4: Search in binary data
    char *res4 = ft_memchr(arr2, 3, sizeof(arr2));
    if (res4)
        printf("Test 4: Found 3 at index %ld\n", res4 - arr2);
    else
        printf("Test 4: 3 not found\n");

    // Test 5: Search for first character
    char *res5 = ft_memchr(arr3, 'a', sizeof(arr3));
    if (res5)
        printf("Test 5: Found 'a' at index %ld\n", res5 - arr3);
    else
        printf("Test 5: 'a' not found\n");

    // Test 6: Search for last character
    char *res6 = ft_memchr(arr3, 'g', sizeof(arr3));
    if (res6)
        printf("Test 6: Found 'g' at index %ld\n", res6 - arr3);
    else
        printf("Test 6: 'g' not found\n");

    return 0;
}*/
