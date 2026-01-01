/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:42:25 by bayam             #+#    #+#             */
/*   Updated: 2025/06/22 20:06:06 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == s || n == 0)
		return (dest);
	if (d < s)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	return (dest);
}
/*#include <stdio.h>
#include <string.h>
int main(void)
{
    char buffer[20] = "Hello, World!";

    printf("Original buffer: %s\n", buffer);

    // Non-overlapping test: copy "Hello" to the end
    ft_memmove(buffer + 7, buffer, 5);
    buffer[12] = '\0'; // Null-terminate for printing
    printf("After non-overlap: %s\n", buffer);

    // Overlapping test: move "Hello, W" 3 bytes forward within buffer
    strcpy(buffer, "Hello, World!");
    ft_memmove(buffer + 3, buffer, 8);
    buffer[11] = '\0'; // Null-terminate for printing
    printf("After overlap:    %s\n", buffer);

    return (0);
}*/
