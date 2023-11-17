#include "monty.h"

/**
 * rotr - rotate the stack to the bottom
 * @stack: Input stack
 * @line_number: Line number
 */

void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *last = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (last->next != NULL)
		last = last->next;

	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
}
