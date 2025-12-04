// Assignment name	: ft_strspn
// Expected files	: ft_strspn.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the strspn function 
// (man strspn).

// The function should be prototyped as follows:

// size_t	ft_strspn(const char *s, const char *accept);
#include <stddef.h>

size_t ft_strspn(const char *s, const char *accept)
{
	int i;
	i = 0;
	while (s[i] != '\0')
	{
		int j;
		j = 0;
		int found_match;
		found_match = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
			{
				found_match = 1;
				break;
			}
			j++;
		}

		if (found_match == 0)
			return (i);
		i++;
	}
	return (i);
}

#include <stdio.h>
#include <string.h>

int main (void)
{
	printf("Mine: %zu | Lib : %zu", ft_strspn("hello world", "hello"), strspn("hello world", "hello"));
}