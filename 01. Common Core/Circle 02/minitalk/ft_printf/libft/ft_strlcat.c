/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:37:57 by bayam             #+#    #+#             */
/*   Updated: 2025/06/03 21:25:56 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	j = 0;
	dest_len = 0;
	src_len = 0;
	while (dest[dest_len] && dest_len < size)
		dest_len++;
	while (src[src_len])
		src_len++;
	if (size == 0 || dest_len >= size)
		return (size + src_len);
	while (src[j] && (dest_len + j + 1) < size)
	{
		dest[dest_len + j] = src[j];
		j++;
	}
	dest[dest_len + j] = '\0';
	return (dest_len + src_len);
}

/*#include <stdio.h>

int main(void)
{
	char buffer[20] = "Hello";
	char *to_add = " World";
	unsigned int result;

	result = ft_strlcat(buffer, to_add, sizeof(buffer));
	printf("Result: %u\n", result);  // Expected: 11
	printf("Buffer: %s\n", buffer);  // Expected: "Hello World"

	return 0;
}*/