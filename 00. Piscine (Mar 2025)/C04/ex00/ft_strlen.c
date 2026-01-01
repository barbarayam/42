/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:29:54 by bayam             #+#    #+#             */
/*   Updated: 2025/03/27 21:09:40 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*#include <stdio.h>
int main(void)
{	
	// Test case 1: Regular string
	char str1[] = "Hello World!";
	printf("The length of the string \"%s\" is %d.\n", str1, ft_strlen(str1));

	// Test case 2: Empty string
	char str2[] = "";
	printf("The length of an empty string is %d\n", ft_strlen(str2));

	// Test case 3: String with special characters
	char str3[] = "!@#$%^&*()";
	printf("The length of the string \"%s\" is %d\n", str3, ft_strlen(str3));

	return(0);
}
*/