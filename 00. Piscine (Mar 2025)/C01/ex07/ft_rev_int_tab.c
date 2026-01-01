/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:18:02 by bayam             #+#    #+#             */
/*   Updated: 2025/03/23 21:28:39 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	start;
	int	end;

	start = 0;
	end = size - 1;
	while (start < end)
	{
		temp = tab[start];
		tab[start] = tab[end];
		tab[end] = temp;
		start++;
		end--;
	}
}

/*#include <stdio.h>

void	print_int_array(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n"); // Move to the next line after printing the array
}

int main(void)
{
	int	array[] = {1, 2, 3, 4, 5};
	int	size = 5;
	
	printf("Original array: ");
	print_int_array(array, size);
	
	ft_rev_int_tab(array, size);

	printf("Reversed array: ");
	print_int_array(array, size);
	
	return (0);
}*/