/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:09:52 by bayam             #+#    #+#             */
/*   Updated: 2025/03/25 20:29:46 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/*#include <stdio.h>
int	main(void)
{
	char *test1 = "123456";
	char *test2 = "123abc";
	char *test3 = "";
	char *test4 = "42isGreat";
	char *test5 = "1!2@3#";
	
	printf("The result for test 1 is %d\n", ft_str_is_numeric(test1));
	printf("The result for test 2 is %d\n", ft_str_is_numeric(test2));
	printf("The result for test 3 is %d\n", ft_str_is_numeric(test3));
	printf("The result for test 4 is %d\n", ft_str_is_numeric(test4));
	printf("The result for test 5 is %d\n", ft_str_is_numeric(test5));

	return 0;
}
*/