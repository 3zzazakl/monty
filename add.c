#include "monty.h"

/**
 * add - adding values.
 * @stack: input stack.
 */
void add(stack_t **stack)
{
	int result;
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Error: can't add, stack too short\n");
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = result;

	top = *stack;
	*stack = (*stack)->next;

	free(top);
}
