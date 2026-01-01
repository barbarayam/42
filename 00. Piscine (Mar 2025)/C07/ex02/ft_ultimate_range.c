/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:49:54 by bayam             #+#    #+#             */
/*   Updated: 2025/04/06 22:04:57 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc((max - min) * sizeof(int));
	if (! *range)
		return (-1);
	while (min < max)
	{
		(*range)[i] = min;
		min ++;
		i ++;
		size ++;
	}
	return (size);
}

/*
# include <stdio.h>
void test_ft_ultimate_range(int min, int max) {
    int *range;
    int size;
    int i;

    printf("Testing ft_ultimate_range with min = %d and max = %d\n", min, max);

    // Call the function
    size = ft_ultimate_range(&range, min, max);

    // Handle the result
    if (size == -1) {
        printf("Memory allocation failed.\n");
    } else if (size == 0) {
        printf("Invalid range: min >= max. Expected size = 0.\n");
        if (range == NULL)
            printf("Range is correctly set to NULL.\n");
        else
            printf("Error: Range should be NULL.\n");
    } else {
        printf("Valid range. Size of array: %d\n", size);
        printf("Array contents: ");
        for (i = 0; i < size; i++)
            printf("%d ", range[i]);
        printf("\n");

        // Free allocated memory to avoid leaks
        free(range);
    }

    printf("\n");
}

int main(void) {
    // Test Cases

    // Case 1: Valid range (min < max)
    test_ft_ultimate_range(5, 10);

    // Case 2: Invalid range (min >= max)
    test_ft_ultimate_range(10, 5);

    // Case 3: Edge case (min == max)
    test_ft_ultimate_range(5, 5);

    // Case 4: Large valid range
    test_ft_ultimate_range(-100, 100);

    // Case 5: Single value range (min = -1, max = 0)
    test_ft_ultimate_range(-1, 0);

    return 0;
}
*/