#include "monty.h"

/**
 * sub - sub elements in the stack.
 * @stack: Input stack.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = result;

	top = *stack;
	*stack = (*stack)->next;

	free(top);
}
