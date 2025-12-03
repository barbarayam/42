// Assignment name  : repeat_alpha
// Expected files   : repeat_alpha.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program called repeat_alpha that takes a string and display it
// repeating each alphabetical character as many times as its alphabetical index,
// followed by a newline.

// 'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

// Case remains unchanged.

// If the number of arguments is not 1, just display a newline.

// Examples:

// $>./repeat_alpha "abc"
// abbccc
// $>./repeat_alpha "Alex." | cat -e
// Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
// $>./repeat_alpha 'abacadaba 42!' | cat -e
// abbacccaddddabba 42!$
// $>./repeat_alpha | cat -e
// $
// $>
// $>./repeat_alpha "" | cat -e
// $
// $>

#include <unistd.h>

void	repeat_char(char c, int count)
{
	while (count > 0)
	{
		write(1, &c, 1);
		count--;
	}
}

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		int i;
		int count;

		i = 0;
		while (av[1][i] != '\0')
		{
			char current_char = av[1][i];

			if(current_char >= 'a' && current_char <= 'z')
			{
				count = current_char - 'a' + 1;
				repeat_char(current_char, count);
			}
			else if (current_char >= 'A' && current_char <= 'Z')
			{
				count = current_char - 'A' + 1;
				repeat_char(current_char, count);
			}
			else
				write(1, &current_char, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

