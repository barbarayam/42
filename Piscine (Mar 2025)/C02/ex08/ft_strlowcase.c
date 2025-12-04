/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 22:09:17 by bayam             #+#    #+#             */
/*   Updated: 2025/03/26 16:48:02 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + ('a' - 'A');
		i++;
	}
	return (str);
}

/*
#include <stdio.h>
int main(void)
{
	char test1[] = "hello";
	char test2[] = "HeLLo WoRLd!";
	char test3[] = "";
	char test4[] = "changetoLOWERCASE";

	printf("The result for test 1 is %s\n", ft_strlowcase(test1));
	printf("The result for test 2 is %s\n", ft_strlowcase(test2));
	printf("The result for test 3 is %s\n", ft_strlowcase(test3));
	printf("The result for test 4 is %s\n", ft_strlowcase(test4));
	
	return 0;
}
*/