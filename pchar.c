#include "monty.h"

/**
 * pchar - print chat at first stack.
 * @stack: input stack
 * @line_number: Line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
		handle_pchar_stack_too_short_error(line_number);
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
