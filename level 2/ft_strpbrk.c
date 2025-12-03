// Assignment name	: ft_strpbrk
// Expected files	: ft_strpbrk.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the function strpbrk
// (man strpbrk).

// The function should be prototyped as follows:

// char	*ft_strpbrk(const char *s1, const char *s2);

#include <stddef.h>

char *ft_strpbrk(const char *s1, const char *s2)
{
	int i;
	i = 0;
	while (s1[i] != '\0')
	{
		int j;
		j = 0;
		while(s2[j] != '\0')
		{
			if(s1[i] == s2[j])
			{
				return((char*)&s1[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

#include <stdio.h>
#include <string.h>

// A helper function to print results neatly
void check_test(char *str, char *accept)
{
    char *res_mine = ft_strpbrk(str, accept);
    char *res_lib  = strpbrk(str, accept);

    printf("String: \"%s\" | Looking for: \"%s\"\n", str, accept);
    
    // Check if both return NULL
    if (res_mine == NULL && res_lib == NULL)
    {
        printf(" -> [OK] Both returned NULL (No match found)\n");
    }
    // Check if both return the same address
    else if (res_mine == res_lib)
    {
        printf(" -> [OK] Match found at char: '%c'\n", *res_mine);
        printf(" -> Remainder of string: \"%s\"\n", res_mine);
    }
    else
    {
        printf(" -> [FAIL] Pointers do not match!\n");
        printf("    Mine: %p\n    Lib : %p\n", res_mine, res_lib);
    }
    printf("----------------------------------------\n");
}

int main(void)
{
    // Test 1: Standard match (should find 'e')
    check_test("Hello World", "aeiou");

    // Test 2: No match (should return NULL)
    check_test("Hello World", "xyz");

    // Test 3: Match at the very beginning (should find 'H')
    check_test("Hello World", "H");

    // Test 4: Empty string input
    check_test("", "aeiou");

    return (0);
}