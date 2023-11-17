#include "monty.h"

/**
 * mul - multiply values.
 * @stack: input stack.
 * @line_number: line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!is_integer((*stack)->next->n) || !is_integer((*stack)->n))
	{
		fprintf(stderr, "L%u: multiplication require integer values\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->n * (*stack)->next->n;
	(*stack)->next->n = result;

	top = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(top);
}
