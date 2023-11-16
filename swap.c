#include "monty.h"

/**
 * swap - swap top elements in stack.
 * @stack: input stack.
 */
void swap(stack_t **stack)
{
	stack_t *top, *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Error: can't swap, stack too short\n");
		exit(EXIT_FAILURE);
	}

	top = *stack;
	next = (*stack)->next;

	top->prev = next;
	top->next = next->next;

	next->prev = NULL;
	next->next = top;

	*stack = next;
}
