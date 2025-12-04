/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:52:10 by bayam             #+#    #+#             */
/*   Updated: 2025/03/26 20:52:43 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_alphanumeric(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i] != '\0')
	{
		if (is_alphanumeric(str[i]))
		{
			if (new_word && str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - ('a' - 'A');
			else if (!new_word && str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] + ('a' - 'A');
			new_word = 0;
		}
		else
			new_word = 1;
		i++;
	}
	return (str);
}

/*#include <stdio.h>

int main(void)
{
    char str[] = "salUt, coMMeNt tu vas ? 42mots quaRante-deux; cinquante+et+un";
    printf("Before:  %s\n", str);
    ft_strcapitalize(str);
    printf("After:   %s\n", str);
    return 0;
}*/
