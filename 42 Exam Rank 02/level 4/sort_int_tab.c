// Assignment name  : sort_int_tab
// Expected files   : sort_int_tab.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write the following function:

// void sort_int_tab(int *tab, unsigned int size);

// It must sort (in-place) the 'tab' int array, that contains exactly 'size'
// members, in ascending order.

// Doubles must be preserved.

// Input is always coherent.

void sort_int_tab(int *tab, unsigned int size)
{
	int tmp;
	unsigned int i;
	unsigned int j;
	
	i = 0;
	while (i < size - 1)
	{
		j = i;
		while (j < size)
		{
			if(tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void print_array(int *tab, int size)
{
    int i = 0;
    while (i < size)
    {
        printf("%d", tab[i]);
        if (i < size - 1)
            printf(", "); // Add comma between numbers
        i++;
    }
    printf("\n");
}

#include <stdio.h>

int main(void)
{
    // --- TEST CASE 1: Standard Random Array ---
    int tab1[] = {5, 2, 9, 1, 5, 6};
    int size1 = 6;

    printf("Test 1 (Random + Duplicate):\n");
    printf("Before: ");
    print_array(tab1, size1);

    sort_int_tab(tab1, size1);

    printf("After:  ");
    print_array(tab1, size1);
    printf("\n");

    // --- TEST CASE 2: Reverse Order ---
    int tab2[] = {9, 8, 7, 6, 5};
    int size2 = 5;

    printf("Test 2 (Reverse Order):\n");
    printf("Before: ");
    print_array(tab2, size2);

    sort_int_tab(tab2, size2);

    printf("After:  ");
    print_array(tab2, size2);
    printf("\n");

    // --- TEST CASE 3: Already Sorted ---
    int tab3[] = {1, 2, 3};
    int size3 = 3;

    printf("Test 3 (Already Sorted):\n");
    printf("Before: ");
    print_array(tab3, size3);

    sort_int_tab(tab3, size3);

    printf("After:  ");
    print_array(tab3, size3);

    return (0);
}