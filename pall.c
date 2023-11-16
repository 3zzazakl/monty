#include "monty.h"

/**
 * pall - pushing all values.
 * @stack: input stack
 */
void pall(stack_t *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}
