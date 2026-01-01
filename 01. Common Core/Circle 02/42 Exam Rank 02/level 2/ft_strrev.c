// Assignment name  : ft_strrev
// Expected files   : ft_strrev.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that reverses (in-place) a string.

// It must return its parameter.

// Your function must be declared as follows:

// char    *ft_strrev(char *str);

char *ft_strrev(char *str)
{
	int i;
	i = 0;

	int len;
	len = 0;

	char temp;
	while(str[len] != '\0')
	{
		len++;
	}
	len = len - 1;
	while (i < len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;

		i++;
		len--;
	}
	return(str);
}
# include <stdio.h>

int main(void)
{
	char str[] = "hello";
	printf("String: hello | Rev: %s\n", ft_strrev(str));
	return (0);
}