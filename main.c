#include "main.h"

/**
 *main - The entry point to the monty compiler program
 *@av: Argument vector
 *@ac: Argument counter
 *Return: 0 in successfull
 */
int main(int ac, char **av)
{
	FILE *monty_file;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(av[1], "r");
	if (monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	interpreter(monty_file);
	fclose(monty_file);
	return (0);
}
