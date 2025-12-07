// Assignment name  : ft_list_size
// Expected files   : ft_list_size.c, ft_list.h
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that returns the number of elements in the linked list that's
// passed to it.

// It must be declared as follows:

// int	ft_list_size(t_list *begin_list);

// You must use the following structure, and turn it in as a file called
// ft_list.h:

// typedef struct    s_list
// {
//     struct s_list *next;
//     void          *data;
// }                 t_list;

#include "ft_list.h"
#include <stddef.h>

int ft_list_size(t_list *begin_list)
{
	int count;
	t_list *current;

	count = 0;
	current = begin_list;
	while (current != NULL)
	{
		count++;
		current = current -> next;
	}
	return (count);
}

// test
#include <stdio.h>

// Prototype your function
int	ft_list_size(t_list *begin_list);

int	main(void)
{
	// 1. Declare three list nodes (variables)
	t_list	elem1;
	t_list	elem2;
	t_list	elem3;

	// 2. Initialize their data (optional, but good practice)
	elem1.data = "First";
	elem2.data = "Second";
	elem3.data = "Third";

	// 3. Link them together manually!
	// elem1 points to elem2
	elem1.next = &elem2;
	// elem2 points to elem3
	elem2.next = &elem3;
	// elem3 is the end, so it points to NULL
	elem3.next = NULL;

	// 4. Test your function
	// Pass the address of the first element (&elem1)
	printf("Size of list: %d\n", ft_list_size(&elem1)); // Expected: 3

	// 5. Edge case: Test an empty list (NULL)
	printf("Size of empty list: %d\n", ft_list_size(NULL)); // Expected: 0

	return (0);
}