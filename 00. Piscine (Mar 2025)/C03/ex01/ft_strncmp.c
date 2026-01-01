/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 21:17:26 by bayam             #+#    #+#             */
/*   Updated: 2025/03/26 22:13:55 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

/*#include <stdio.h>

int main()
{
    char str1[] = "hello";
    char str2[] = "hell";
    char str3[] = "world";

    printf("print diff : %d\n", ft_strncmp(str1, str2, 4));
    printf("print diff : %d\n", ft_strncmp(str1, str2, 5));
    printf("print diff : %d\n", ft_strncmp(str1, str3, 3));

    return 0;
}
*/