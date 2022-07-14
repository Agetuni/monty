#include "main.h"

/**
 *push - Adds data to the top of the stack
 *
 *@stack: The stack data
 *@line_number: The current line number of the file
 *Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (!op_value || (atoi(op_value) == 0 && strcmp(op_value, "0") != 0))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(op_value);
	new->prev = *stack;
	new->next = NULL;
	if (*stack != NULL)
		(*stack)->next = new;
	*stack = new;
}
