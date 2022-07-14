#include "main.h"

/**
 *interpreter - loops through the lines of a monty file
 *
 *@monty_file: Monty language file
 *Return: void
 */
void interpreter(FILE *monty_file)
{
	char buffer[BUFSIZ];
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	int word_count, i;
	char **args;

	while (fgets(buffer, BUFSIZ, monty_file))
	{
		i = 0;
		line_number++;
		word_count = countWords(buffer);
		if (word_count != 0)
		{
			clean_buffer(buffer);
			args = malloc(sizeof(*args) * (word_count + 1));
			if (args == NULL)
			{
				fprintf(stderr, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}
			args[i] = strtok(buffer, " ");
			for (i = 1; i < word_count; i++)
			{
				args[i] = strtok(NULL, " ");
			}
			args[i] = NULL;
			get_opcode(args, line_number, &stack);
			free(args);
		}
	}
	free_stack(&stack);
}

/**
 *clean_buffer - removes all unwanted chars from buffert (\n, \t)
 *
 *@buffer: The buffet
 *Return: void
 */
void clean_buffer(char *buffer)
{
	char *ptr_1, *ptr_2;

	ptr_1 = strchr(buffer, '\n');
	ptr_2 = strchr(buffer, '\t');
	if (ptr_1)
		*ptr_1 = '\0';
	if (ptr_2)
		*ptr_2 = '\0';
}
