// Assignment name  : inter
// Expected files   : inter.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in both strings, in the order they appear in the first
// one.

// The display will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Examples:

// $>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// padinto$
// $>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6ewg4$
// $>./inter "rien" "cette phrase ne cache rien" | cat -e
// rien$
// $>./inter | cat -e
// $

#include <unistd.h>
int main(int ac, char * av[])
{
	if (ac == 3)
	{
		int i;
		i = 0;
		int j;
		int k;
		while (av[1][i] != '\0')
		{
			j = 0;
			while(j <i)
			{
				if (av[1][i] == av[1][j])
				{
					break;
				}
				j++;
			}
			if (j== i)
			{
				k = 0;
				while (av[2][k] != '\0')
				{
					if(av[2][k] == av[1][i])
					{
						write(1, &av[1][i],1);
						break;
					}
					k++;
				}
			}
			i++;
		}
	write(1, "\n", 1);
	}
}
