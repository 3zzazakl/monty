#include "monty.h"

/**
 * _div - divide values
 * @stack: input stack
 */
void _div(stack_t **stack)
{
	int result;
	stack_t *top;

	if (*stack ==  NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Error: can't div, stack too short\n");
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "Error: division by zero\n");
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n / (*stack)->n;

	(*stack)->next->n = result;

	top = *stack;
	*stack = (*stack)->next;

	free(top);
}
