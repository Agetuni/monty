#include "main.h"
/**
 * countWords - counts the number of words in input
 *
 * @input: A string
 * Return: The number of words in input
 */
int countWords(char *input)
{
	int isWord = 0, count = 0;

	if (!input)
		return (0);
	while (*input)
	{
		if (*input != ' ')
			isWord = 1;
		else
		{
			if (isWord)
				count++;
			isWord = 0;
		}
		input++;
	}
	count = isWord ? count + 1 : count;
	return (count);
}
