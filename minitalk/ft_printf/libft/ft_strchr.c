/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 21:48:07 by bayam             #+#    #+#             */
/*   Updated: 2025/06/22 22:46:05 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

/*#include <stdio.h>

int main(void)
{
    // Test 1: Character is present
    char *found = ft_strchr("Hello", 'e');
    if (found)
        printf("Test 1: Found 'e' in \"Hello\" at: \"%s\"\n", found);
    else
        printf("Test 1: 'e' not found in \"Hello\"\n");

    // Test 2: Character is not present
    char *not_found = ft_strchr("Hello", 'z');
    if (not_found)
        printf("Test 2: Found 'z' in \"Hello\" at: \"%s\"\n", not_found);
    else
        printf("Test 2: 'z' not found in \"Hello\"\n");

    // Test 3: Character is at the start
    char *start = ft_strchr("Hello", 'H');
    if (start)
        printf("Test 3: Found 'H' in \"Hello\" at: \"%s\"\n", start);

    // Test 4: Character is at the end
    char *end = ft_strchr("Hello", 'o');
    if (end)
        printf("Test 4: Found 'o' in \"Hello\" at: \"%s\"\n", end);

    // Test 5: Search for the null terminator
    char *null_term = ft_strchr("Hello", '\0');
    if (null_term)
        printf("Test 5: Found '\\0' in \"Hello\" at: \"%s\"\n", null_term);

    return 0;
}*/
