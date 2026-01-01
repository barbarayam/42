/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:11:10 by bayam             #+#    #+#             */
/*   Updated: 2025/03/26 22:11:51 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*#include <stdio.h>

int ft_strcmp(char *s1, char *s2);

int main()
{
    char str1[] = "hello";
    char str2[] = "world";
    char str3[] = "hello";

    printf("print diff : %d\n",ft_strcmp(str1, str2));
    printf("print diff : %d\n",ft_strcmp(str1, str3));

    return 0;
} 
*/	
