#include "monty.h"

/**
 * _div - divide values
 * @stack: input stack
 * @line_number: line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *top;

	if (*stack ==  NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n / (*stack)->n;

	(*stack)->next->n = result;

	top = *stack;
	*stack = (*stack)->next;

	free(top);
}
