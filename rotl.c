#include "monty.h"

/**
 * rotl - rotates the stack to the top.
 * @stack: Input stack
 * @line_number: line number
 */
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	last = *stack;
	while (last->next != NULL)
		last = last->next;

	last->next = *stack;
	(*stack)->prev = last;
	*stack = (*stack)->next;
	last->next->prev = NULL;
	last->next = NULL;
}
