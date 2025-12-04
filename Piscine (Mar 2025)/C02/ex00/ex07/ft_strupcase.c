/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:47:13 by bayam             #+#    #+#             */
/*   Updated: 2025/03/25 22:08:09 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - ('a' - 'A');
		i++;
	}
	return (str);
}

/*#include <stdio.h>
int main(void)
{
	char test1[] = "hello";
	char test2[] = "HeLLo WoRLd!";
	char test3[] = "";
	char test4[] = "alreadyUPPERCASE";

	printf("The result for test 1 is %s\n", ft_strupcase(test1));
	printf("The result for test 2 is %s\n", ft_strupcase(test2));
	printf("The result for test 3 is %s\n", ft_strupcase(test3));
	printf("The result for test 4 is %s\n", ft_strupcase(test4));
	
	return 0;
}
*/
