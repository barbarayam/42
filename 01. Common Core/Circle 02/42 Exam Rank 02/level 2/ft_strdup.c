// Expected files   : ft_strdup.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strdup (man strdup).

// Your function must be declared as follows:

// char    *ft_strdup(char *src);

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int i;
	i = 0;
	int len = 0;
	char *dest;

	while(src[len] != '\0')
	{
		len++;
	}

	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

# include <stdio.h>
# include <string.h>

int main(void)
{
	char *original = "Hello, Coding Partner";
	char *my_copy;
	char *lib_copy;

	my_copy = ft_strdup(original);
	lib_copy = strdup(original);

	if (my_copy == NULL || lib_copy == NULL)
        return (1); // Safety check

	// print results
	printf("My Copy: 		%s\n", my_copy);
	printf("Library Copy: 	%s\n", lib_copy);

	// verify memory addresses
	printf("Original Address:	%p\n", (void*)original);
	printf("My Copy Address:    %p\n", (void*)my_copy);

	// clean up
	free(my_copy);
	free(lib_copy);

	return (0);
}