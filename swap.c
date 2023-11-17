#include "monty.h"

/**
 * swap - swap top elements in stack.
 * @stack: input stack.
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	next = top->next;

	top->next = next->next;
	top->prev = next;

	if (next->next != NULL)
		next->next->prev = top;

	next->next = top;
	next->prev = NULL;

	*stack = next;
}
