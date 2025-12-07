// Assignment name  : add_prime_sum
// Expected files   : add_prime_sum.c
// Allowed functions: write, exit
// --------------------------------------------------------------------------------

// Write a program that takes a positive integer as argument and displays the sum
// of all prime numbers inferior or equal to it followed by a newline.

// If the number of arguments is not 1, or the argument is not a positive number,
// just display 0 followed by a newline.

// Yes, the examples are right.

// Examples:

// $>./add_prime_sum 5
// 10
// $>./add_prime_sum 7 | cat -e
// 17$
// $>./add_prime_sum | cat -e
// 0$
// $>

#include <unistd.h>

int ft_atoi(const char *str)
{
	int i;
	i = 0;
	int sign;
	sign = 1;
	int result;
	result = 0;
	while (str[i] != '\0')
	{
		while (str[i] >= 9 && str[i] <= 13 || str[i] == 32 )
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign = sign * -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
			i++;
		}
		return (result * sign);		
	}
}

int is_prime(int number)
{
	int i;
	i = 0;
	if (number <= 1)
		return (0);
	i = 2;

	while (i * i <= number)
	{
		if (number % i == 0)
			return(0);
		i++;
	}
	return (1);
}
void ft_putnbr(int n)
{
	char c;
	if (n >= 10)
	{
		ft_putnbr( n /10);
	}
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int main (int ac, char *av[])
{
	int number;
	int sum;
	int i;

	if (ac != 2)
	{
		write(1, "0\n", 2);
		return(0);
	}

	number = ft_atoi(av[1]);

	if (number <= 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	sum = 0;
	i = 2;
	while (i <= number)
	{
			if (is_prime(i))
				sum += i;
			i++;
	}
	ft_putnbr(sum);
	write(1, "\n", 1);
	return (0);
}

