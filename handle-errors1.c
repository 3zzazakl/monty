#include "monty.h"
/**
 * handle_invalid_instruction - check invalid instruction
 * @instruction: input
 * @line_number: line number.
 */
void handle_invalid_instruction(const char *instruction, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, instruction);
	exit(EXIT_FAILURE);
}
/**
 * handle_push_integer_error - handle push errors
 * @line_number: line number
 */
void handle_push_integer_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}
/**
 * handle_pint_empty_stack_error - handle pint empty.
 * @line_number: Line number
 */
void handle_pint_empty_stack_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
}
/**
 * handle_pop_empty_stack_error - handle pop empty stack.
 * @line_number: line number.
 */
void handle_pop_empty_stack_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
}
/**
 * handle_swap_stack_too_short_error - handle swap too short in stack
 * @line_number: line number
 */
void handle_swap_stack_too_short_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't swap stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
