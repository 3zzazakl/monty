#include "monty.h"

/**
 * free_stack - free stack memory
 * @stack: current stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *current;

	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
	free(stack);
}
