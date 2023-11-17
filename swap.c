#include "monty.h"

/**
 * swap - swap top elements in stack.
 * @stack: input stack.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: Error: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	next = top->next;

	top->prev = next;
	top->next = next->next;

	if (next->next != NULL)
		next->next->prev = top;

	next->prev = NULL;
	next->next = top;

	*stack = next;
}
