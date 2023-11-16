#include "monty.h"

/**
 * sub - sub elements in the stack.
 * @stack: Input stack.
 */
void sub(stack_t **stack)
{
	int result;
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Error: can't sub, stack too short\n");
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = result;

	top = *stack;
	*stack = (*stack)->next;

	free(top);
}
