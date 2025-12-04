// Assignment name  : ft_atoi
// Expected files   : ft_atoi.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str to an integer (type int)
// and returns it.

// It works much like the standard atoi(const char *str) function, see the man.

// Your function must be declared as follows:

// int	ft_atoi(const char *str);

int ft_isspace(int c)
{
	if (c == ' ' || c >= 9 && c <= 13)
		return (1);
	return (0);
}


int ft_atoi(const char *str)
{
	int i;
	int sign;
	i = 0;
	sign = 1;
	int nbr;
	nbr = 0;

	while (ft_isspace(str[i]))
	{
		i++;
	}

	if (str[i] == '+' )
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

#include <stdio.h>
#include <stdlib.h> // For the real atoi

int ft_atoi(const char *str); // Your function prototype

int main(void)
{
    // Case 1: Simple number
    char *s1 = "42";
    printf("Test 1: %s\n", s1);
    printf("Mine: %d | Real: %d\n\n", ft_atoi(s1), atoi(s1));

    // Case 2: Negative number
    char *s2 = "-1234";
    printf("Test 2: %s\n", s2);
    printf("Mine: %d | Real: %d\n\n", ft_atoi(s2), atoi(s2));

    // Case 3: Weird spacing (Spaces and Tabs)
    // Note: \t is a tab, \n is newline
    char *s3 = "    \t\n  1337";
    printf("Test 3: %s\n", s3);
    printf("Mine: %d | Real: %d\n\n", ft_atoi(s3), atoi(s3));

    // Case 4: Explicit Plus sign
    char *s4 = "+99";
    printf("Test 4: %s\n", s4);
    printf("Mine: %d | Real: %d\n\n", ft_atoi(s4), atoi(s4));

    // Case 5: Garbage after number (Should stop reading)
    char *s5 = "567xyz";
    printf("Test 5: %s\n", s5);
    printf("Mine: %d | Real: %d\n\n", ft_atoi(s5), atoi(s5));
    
    // Case 6: Garbage BEFORE number (Should be 0)
    char *s6 = "abc567";
    printf("Test 6: %s\n", s6);
    printf("Mine: %d | Real: %d\n", ft_atoi(s6), atoi(s6));

    return (0);
}