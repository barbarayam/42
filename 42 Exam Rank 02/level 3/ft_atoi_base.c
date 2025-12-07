// Assignment name  : ft_atoi_base
// Expected files   : ft_atoi_base.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str (base N <= 16)
// to an integer (base 10) and returns it.

// The characters recognized in the input are: 0123456789abcdef
// Those are, of course, to be trimmed according to the requested base. For
// example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

// Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

// Minus signs ('-') are interpreted only if they are the first character of the
// string.

// Your function must be declared as follows:

// int	ft_atoi_base(const char *str, int str_base);

// returns -1 if the character is not a digit/ letter
int get_value(char c)
{
	if (c >= '0' && c<= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
	int i;
	i = 0;
	int result;
	result = 0;
	int sign;
	sign = 1;
	int value;

	// check validity of the base (safety check)
	if (str_base < 2 || str_base > 16)
		return (0);

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}

	while (str[i])
	{
		value = get_value(str[i]);
		if (value == -1 || value >= str_base)
			break;
		result = result * str_base + value;
		i++;
	}
	return (result * sign);
}

//test
#include <stdio.h>

int		ft_atoi_base(const char *str, int str_base);

int		main(void)
{
	printf("Base 10 '123': %d\n", ft_atoi_base("123", 10)); // Expected: 123
	printf("Base 2 '101': %d\n", ft_atoi_base("101", 2));   // Expected: 5
	printf("Base 16 'FF': %d\n", ft_atoi_base("FF", 16));   // Expected: 255
	printf("Base 16 '-1A': %d\n", ft_atoi_base("-1A", 16)); // Expected: -26
	printf("Base 4 '15': %d\n", ft_atoi_base("15", 4));     // Expected: 1 (stops at 5 because 5 >= base 4)
}