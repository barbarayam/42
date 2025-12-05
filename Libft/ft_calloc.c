/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:33:39 by bayam             #+#    #+#             */
/*   Updated: 2025/06/22 19:22:07 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;
	size_t	max_size;

	max_size = (size_t) - 1;
	if (nmemb != 0 && size != 0 && size > max_size / nmemb)
		return (NULL);
	total = nmemb * size;
	ptr = malloc(total);
	if (ptr)
		ft_memset(ptr, 0, total);
	return (ptr);
}
