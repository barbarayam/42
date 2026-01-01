// Assignment name  : ft_rrange
// Expected files   : ft_rrange.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_rrange(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at end and end at start (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 3, 2 and 1
// - With (-1, 2) you will return an array containing 2, 1, 0 and -1.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing -3, -2, -1 and 0.

#include <stdlib.h>

int *ft_rrange(int start, int end)
{
	int *rrange;
	int i;
	int len;

	i = 0;
	len = 0;

	if (start < end)
		len = end - start + 1;
	else
		len = start - end + 1;

	rrange = malloc (sizeof (int) * (len));
	if (!rrange)
		return (NULL);
	while (i < len)
	{
		rrange[i] = end;
		if (end > start)
			end--;
		else
			end++;
		i++;
	}
	return (rrange);
}

//test case
#include <stdio.h>

int		*ft_rrange(int start, int end);

int		main(void)
{
	int *arr;
	int i =0;
	
	arr = ft_rrange(1, 3);
	int len = 3 - 1 + 1;
	while (i < len)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	free(arr); //always free the malloc
	return (0);
}