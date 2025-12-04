/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:13:31 by bayam             #+#    #+#             */
/*   Updated: 2025/03/25 21:46:13 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

/*#include <stdio.h>
int	main(void)
{
	char *test1 = "HelloWorld";
	char *test2 = "12345";
	char *test3 = "";
	char *test4 = "1!2@3#";
	char *test5 = "Hello\nWorld";
	
	printf("The result for test 1 is %d\n", ft_str_is_printable(test1));
	printf("The result for test 2 is %d\n", ft_str_is_printable(test2));
	printf("The result for test 3 is %d\n", ft_str_is_printable(test3));
	printf("The result for test 4 is %d\n", ft_str_is_printable(test4));
	printf("The result for test 5 is %d\n", ft_str_is_printable(test5));

	return 0;
}*/
