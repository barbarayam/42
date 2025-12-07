// Assignment name  : pgcd
// Expected files   : pgcd.c
// Allowed functions: printf, atoi, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes two strings representing two strictly positive
// integers that fit in an int.

// Display their highest common denominator followed by a newline (It's always a
// strictly positive integer).

// If the number of parameters is not 2, display a newline.

// Examples:

// $> ./pgcd 42 10 | cat -e
// 2$
// $> ./pgcd 42 12 | cat -e
// 6$
// $> ./pgcd 14 77 | cat -e
// 7$
// $> ./pgcd 17 3 | cat -e
// 1$
// $> ./pgcd | cat -e
// $

#include <stdio.h>
#include <stdlib.h>

int main (int ac, char *av[])
{
	if (ac == 3)
	{
		int a;
		int b;
		int hcf;
		a = atoi(av[1]);
		b = atoi(av[2]);
		if (a > b)
			hcf = b;
		else
			hcf = a;
		while (hcf > 0)
		{
			if (a % hcf == 0 && b % hcf == 0)
			{
				printf("%d", hcf);
				break;
			}
			else
				hcf--;		
		}
	}
	printf("\n");
	return (0);
}