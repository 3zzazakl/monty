#include "monty.h"

/**
 * pint - print the top value of stack
 * @stack: input stack
 */
void pint(stack_t *stack)
{
	if (stack == NULL)
	{
		fprintf(stderr, "Error: can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}
	printf("%d\n", stack->n);
}
