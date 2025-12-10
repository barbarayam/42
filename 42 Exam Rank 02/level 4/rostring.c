// Assignment name  : rostring
// Expected files   : rostring.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays this string after rotating it
// one word to the left.

// Thus, the first word becomes the last, and others stay in the same order.

// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string.

// Words will be separated by only one space in the output.

// If there's less than one argument, the program displays \n.

// Example:

// $>./rostring "abc   " | cat -e
// abc$
// $>
// $>./rostring "Que la      lumiere soit et la lumiere fut"
// la lumiere soit et la lumiere fut Que
// $>
// $>./rostring "     AkjhZ zLKIJz , 23y"
// zLKIJz , 23y AkjhZ
// $>
// $>./rostring "first" "2" "11000000"
// first
// $>
// $>./rostring | cat -e
// $
// $

#include <unistd.h>
#include <stdlib.h>

void rostring(char *str)
{
    int i = 0;
    int first_word_start = 0;
    int first_word_end = 0;
    int flag = 0; // Helps us manage spaces between words

    // 1. Skip leading spaces/tabs
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    
    // 2. Capture the First Word (Start & End)
    first_word_start = i;
    while (str[i] && str[i] != ' ' && str[i] != '\t')
        i++;
    first_word_end = i;

    // 3. Loop through the REST of the string
    while (str[i])
    {
        // Skip spaces between words
        while (str[i] && (str[i] == ' ' || str[i] == '\t'))
            i++;
        
        // If we found a subsequent word...
        if (str[i])
        {
            // Print a space separator (but only if we already printed words)
            // Or simply: "If this is a new word, print space + word"
            
            // Note: Since we are moving the FIRST word to the end, 
            // any word we find here is technically the "beginning" of our output.
            // But if we find MULTIPLE words here, they need spaces between them.
            if (flag == 1)
                write(1, " ", 1);
            
            flag = 1; // Mark that we have printed at least one word from the "rest" body

            // Print the current word
            while (str[i] && str[i] != ' ' && str[i] != '\t')
            {
                write(1, &str[i], 1);
                i++;
            }
        }
    }

    // 4. Print the First Word at the very end
    // Only if there WAS a first word to begin with
    if (first_word_end > first_word_start)
    {
        // If we printed other words (flag is 1), we need a space before the final word
        if (flag == 1)
            write(1, " ", 1);
            
        // Print the saved first word
        while (first_word_start < first_word_end)
        {
            write(1, &str[first_word_start], 1);
            first_word_start++;
        }
    }
}

int main (int ac, char *av[])
{
	int i;
	int len;
	int start;
	int end;

	if (ac >= 1)
	{
		rostring(av[1]);
	}
	write(1, "\n", 1);
	return (0)
}