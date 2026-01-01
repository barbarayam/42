/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:25:45 by bayam             #+#    #+#             */
/*   Updated: 2025/06/03 20:21:04 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
    // Test 1: Identical strings
    char a[] = "abcdef";
    char b[] = "abcdef";
    int res1 = ft_memcmp(a, b, 6);
    printf("Test 1: %d (expected 0)\n", res1);

    // Test 2: Different strings, first difference in middle
    char c[] = "abcxef";
    int res2 = ft_memcmp(a, c, 6);
    printf("Test 2: %d (expected < 0)\n", res2);

    // Test 3: Different strings, first difference at end
    char d[] = "abcdeg";
    int res3 = ft_memcmp(a, d, 6);
    printf("Test 3: %d (expected < 0)\n", res3);

    // Test 4: Compare only part of the arrays
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 6};
    int res4 = ft_memcmp(arr1, arr2, 4 * sizeof(int));
    printf("Test 4: %d (expected 0)\n", res4);

    int res5 = ft_memcmp(arr1, arr2, 5 * sizeof(int));
    printf("Test 5: %d (expected < 0)\n", res5);

    // Test 5: Case sensitivity
    char e[] = "ABCDEF";
    int res6 = ft_memcmp(a, e, 6);
    printf("Test 6: %d (expected > 0)\n", res6);

    return 0;
}*/