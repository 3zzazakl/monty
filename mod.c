#include "monty.h"

/**
 * mod - calculate modulus of values.
 * @stack: Input stack
 */
void mod(stack_t **stack)
{
	int top, second_top, result;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Erorr: can't mod, stack too short\n");
		exit(EXIT_FAILURE);
	}

	top = (*stack)->n;
	second_top = (*stack)->next->n;

	if (top == 0)
	{
		fprintf(stderr, "Error: division by zero\n");
		exit(EXIT_FAILURE);
	}

	result = second_top % top;
	(*stack)->next->n = result;

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
