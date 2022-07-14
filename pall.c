#include "main.h"

/**
 *pall - prints all the elements in the stack
 *
 *@stack: The stack
 *@line_number: The current line number of the monty file
 *Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	(void)line_number;
	while (ptr)
	{
		fprintf(stdout, "%d\n", ptr->n);
		ptr = ptr->prev;
	}
}
