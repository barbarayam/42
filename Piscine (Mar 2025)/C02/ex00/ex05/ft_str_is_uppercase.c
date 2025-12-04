/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:53:29 by bayam             #+#    #+#             */
/*   Updated: 2025/03/25 21:12:14 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{	
	int	i;
	
	i = 0;
	if (str[i] == '\0')
		return (1);
	while( str[i] != '\0')
	{
		if (str[i] < 'A' || str[i] > 'Z')
			return (0);
		i++;
	}
	return (1);
}

/*#include <stdio.h>
int	main(void)
{
	char *test1 = "ABCDE";
	char *test2 = "ABCde";
	char *test3 = "";
	char *test4 = "42isGreat";
	char *test5 = "1!2@3#";
	
	printf("The result for test 1 is %d\n", ft_str_is_uppercase(test1));
	printf("The result for test 2 is %d\n", ft_str_is_uppercase(test2));
	printf("The result for test 3 is %d\n", ft_str_is_uppercase(test3));
	printf("The result for test 4 is %d\n", ft_str_is_uppercase(test4));
	printf("The result for test 5 is %d\n", ft_str_is_uppercase(test5));

	return 0;
}
*/