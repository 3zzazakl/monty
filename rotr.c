#include "monty.h"

/**
 * rotr - rotate the stack to the bottom
 * @stack: Input stack
 * @line_number: Line number
 */

void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	while (last->next != NULL)
		last = last->next;

	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	last->prev->next = NULL;
	last->prev = NULL;
}
