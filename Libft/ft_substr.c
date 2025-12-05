/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:59:46 by bayam             #+#    #+#             */
/*   Updated: 2025/07/05 19:24:07 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = 0;
	while (s[s_len])
		s_len ++;
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

/*#include <stdio.h>
int main (void)
{
	char *sub1 = ft_substr("Hello World", 6, 5); // Returns "World"
	char *sub2 = ft_substr("Hello", 10, 3);    // Returns ""
	
	if (sub1)
    {
        printf("Substring 1: '%s'\n", sub1);
        free(sub1);  // Free allocated memory
    }
    if (sub2)
    {
        printf("Substring 2: '%s'\n", sub2);
        free(sub2);  // Free allocated memory
    }

    return (0);
}*/