/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:06:29 by bayam             #+#    #+#             */
/*   Updated: 2025/03/25 20:08:33 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_alpha_char(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!is_alpha_char(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*#include <stdio.h>

int main(void)
{
    // Test cases
    char *test1 = "HelloWorld";       // return 1
    char *test2 = "Hello123";         // return 0
    char *test3 = "";                 // return 1
    char *test4 = "Hello World";      // return 0
    char *test5 = "JustLetters";      // return 1
    char *test6 = "symbols!@#";       // return 0
    char *test7 = "MIXEDcase";        // return 1

    printf("Test 1: %d\n", ft_str_is_alpha(test1));
    printf("Test 2: %d\n", ft_str_is_alpha(test2));
    printf("Test 3: %d\n", ft_str_is_alpha(test3));
    printf("Test 4: %d\n", ft_str_is_alpha(test4));
    printf("Test 5: %d\n", ft_str_is_alpha(test5));
    printf("Test 6: %d\n", ft_str_is_alpha(test6));
    printf("Test 7: %d\n", ft_str_is_alpha(test7));

    return 0;
}
*/