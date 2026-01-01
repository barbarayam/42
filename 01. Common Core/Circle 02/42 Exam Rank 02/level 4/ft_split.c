// Assignment name  : ft_split
// Expected files   : ft_split.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes a string, splits it into words, and returns them as
// a NULL-terminated array of strings.

// A "word" is defined as a part of a string delimited either by spaces/tabs/new
// lines, or by the start/end of the string.

// Your function must be declared as follows:

// char    **ft_split(char *str);

#include <stdlib.h>

int is_sep(char c)
{
	return (c == ' ' || c == '\t' | c == '\0');
}

int count_words(char *str)
{
	int i;
	i = 0;
	int words;
	words = 0;
	while (str[i] != '\0')
	{
		if (!is_sep(str[i]) && (i=0 || is_sep[i-1]))
			words++;
		i++
	}
	return (words);
}

char *malloc_word(char *str)
{
	int len;
	len = 0;
	int i;
	i = 0;
	char *word;

	while(str[len] && !is_sep(str[len]))
		len++;

	word = malloc(sizeof(char)*(len+1));
	if (!word)
		return (NULL);
	while (i <len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return(word);
}

char **ft_split(char *str)
{
	char **array;
	int i;
	i = 0;
	int j;
	j = 0;
	array = malloc(sizeof(char *) * (count_words(str)+ 1));
	if (!array)
		return (NULL);
	while (str[i])
	{
		while(str[i] && is_sep(str[i]))
			i++;
		if(str[i] && !is_sep(str[i]))
		{
			array[j] = malloc_word(&str[i]);
			j++;
			while(str[i] && !is_sep(str[i]))
				i++;
		}
	}
	array[j] = NULL;
	return (array);
}