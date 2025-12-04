// Assignment name  : ft_strcmp
// Expected files   : ft_strcmp.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strcmp (man strcmp).

// Your function must be declared as follows:

// int    ft_strcmp(char *s1, char *s2);

int ft_strcmp(char *s1, char *s2)
{
	int i;
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{		
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

#include <string.h>
#include <stdio.h>

int main(void)
{
    // Case 1: Identical
    printf("Same:   Lib: %d | Mine: %d\n", strcmp("Hello", "Hello"), ft_strcmp("Hello", "Hello"));

    // Case 2: Different (Your code would hang here)
    printf("Diff:   Lib: %d | Mine: %d\n", strcmp("A", "B"), ft_strcmp("A", "B"));

    // Case 3: Different Lengths (Your code would print 0 here)
    printf("Length: Lib: %d | Mine: %d\n", strcmp("AB", "ABC"), ft_strcmp("AB", "ABC"));
    
    return (0);
}