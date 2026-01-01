/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 22:13:10 by bayam             #+#    #+#             */
/*   Updated: 2025/06/03 15:53:19 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

/*#include <stdio.h>

char *ft_strrchr(const char *s, int c);  // your function prototype

int main(void)
{
    const char *test1 = "hello world";
    const char *test2 = "42 is the answer";
    const char *test3 = "abcdef";
    const char *test4 = "";
    const char *test5 = "multiple e's here";
    const char *test6 = "abcabcabc";
    
    // Test 1: character exists once
    printf("Test 1: %p\n", ft_strrchr(test1, 'w'));

    // Test 2: character does not exist
    printf("Test 2: %p\n", ft_strrchr(test2, 'z'));

    // Test 3: search for '\0'
    printf("Test 3: %p\n", ft_strrchr(test3, '\0'));

    // Test 4: empty string
    printf("Test 4: %p\n", ft_strrchr(test4, 'a'));

    // Test 5: multiple occurrences
    printf("Test 5: %p\n", ft_strrchr(test5, 'e'));

    // Test 6: multiple identical characters
    printf("Test 6: %p\n", ft_strrchr(test6, 'a'));

    // Test 7: character at first position
    printf("Test 7: %p\n", ft_strrchr(test1, 'h'));
	
    return 0;
}*/