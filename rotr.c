#include "monty.h"

/**
 * rotr - rotate the stack to the bottom
 * @stack: Input stack
 * @line_number: Line number
 */

void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *last, *new_top;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	while (last->next != NULL)
	{
		last = last->next;
	}

	new_top = last->next;
	new_top->prev = NULL;
	last->next = NULL;

	while (new_top->next != NULL)
	{
		new_top = new_top->next;
	}

	new_top->next = *stack;
	(*stack)->prev = new_top;
	*stack = new_top->next;
	(*stack)->prev = NULL;
}
