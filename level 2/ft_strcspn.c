// Assignment name	: ft_strcspn
// Expected files	: ft_strcspn.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the function strcspn
// (man strcspn).

// The function should be prototyped as follows:

// size_t	ft_strcspn(const char *s, const char *reject);

#include <stddef.h>

size_t ft_strcspn(const char *s, const char *reject)
{
	int i;
	i = 0;

	while (s[i] != '\0')
	{
		int j;
		j = 0;

		while (reject[j] != '\0')
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
# include <stdio.h>
# include <string.h>

int main (void)
{
	printf("Mine : %zu, Lib : %zu\n", ft_strcspn("hello world", "ord"),strcspn("hello world", "ord"));
}
