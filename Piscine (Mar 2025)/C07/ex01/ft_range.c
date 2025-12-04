/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:43:35 by bayam             #+#    #+#             */
/*   Updated: 2025/04/06 20:01:14 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*range;

	i = 0;
	if (min >= max)
		return (0);
	range = (int *)malloc((max - min) * sizeof(int));
	if (!range)
		return (0);
	while (min < max)
	{
		range[i] = min;
		min ++;
		i++;
	}
	return (range);
}

/*#include <stdio.h>
int main(void)
{
    int *range;
    int i;

    range = ft_range(5, 10); // Create an array with values from 5 to 9
    if (!range)
    {
        printf("Invalid range or memory allocation failed\n");
        return (1);
    }

    i = 0;
    while (i < 10 - 5) // Print all elements in the range
    {
        printf("%d ", range[i]);
        i++;
    }
    printf("\n");

    free(range); // Free allocated memory
    return (0);
}*/