#include "main.h"

/**
 *free_stack - Frees the stack using in interpreter
 *
 *@stack: The stack pointer
 *Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *ptr;

	while (*stack)
	{
		ptr = *stack;
		*stack = (*stack)->prev;
		free(ptr);
	}
}
