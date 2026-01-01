/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 22:26:43 by bayam             #+#    #+#             */
/*   Updated: 2025/07/01 17:49:51 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] != '\0' && (i + j) < len && big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *text1 = "hello world";
    const char *text2 = "42 is the answer";
    const char *text3 = "abcdef";
    const char *text4 = "";
    const char *text5 = "repeat repeat repeat";

    // Test 1: normal match inside length limit
    printf("Test 1: %s\n", ft_strnstr(text1, "world", 11));

    // Test 2: match exists but outside length limit
    printf("Test 2: %s\n", ft_strnstr(text1, "world", 5));

    // Test 3: 'little' is an empty string (should return big)
    printf("Test 3: %s\n", ft_strnstr(text1, "", 11));

    // Test 4: 'big' is an empty string, 'little' is not (should return NULL)
    printf("Test 4: %s\n", ft_strnstr(text4, "abc", 5));

    // Test 5: both strings are empty (should return big)
    printf("Test 5: %s\n", ft_strnstr(text4, "", 5));

    // Test 6: match at the start of 'big'
    printf("Test 6: %s\n", ft_strnstr(text2, "42", 20));

    // Test 7: multiple possible matches — should return the first one
    printf("Test 7: %s\n", ft_strnstr(text5, "repeat", 20));

    // Test 8: match exists, length limit cuts it off mid-word
    printf("Test 8: %s\n", ft_strnstr(text5, "repeat", 5));

    // Test 9: search for substring not in big
    printf("Test 9: %s\n", ft_strnstr(text1, "planet", 20));

    return 0;
}*/
