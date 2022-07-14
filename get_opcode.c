#include "main.h"

/**
 *get_opcode - searches thtough arguments for opcodes
 *
 *@args: The argument list
 *Return: 0 if succesful, 1 if not
 */

char *op_value = NULL;

int get_opcode(char **args, unsigned int line_number, stack_t **stack)
{
	int i;
	void (*f)(stack_t **stack, unsigned int line_number);

	instruction_t codes[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; codes[i].opcode; i++)
	{
		if (strcmp(args[0], codes[i].opcode) == 0)
		{
			if (strcmp(args[0], "push") == 0)
				op_value = args[1];
			f = codes[i].f;
			f(stack, line_number);
			return (0);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, args[0]);
	exit(EXIT_FAILURE);
	return (1);
}
