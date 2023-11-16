#include "monty.h"

/**
 * pstr - printing the string at top of the stack.
 * @stack: Input stack.
 * @line_number: Line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL && current->n != 0)
	{
		if (current->n < 0 || current->n > 127)
		{
			fprintf(stderr, "L%d: can't pstr, value not in ASCII table\n", line_number);
			exit(EXIT_FAILURE);
		}
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
