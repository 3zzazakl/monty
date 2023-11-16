#include "monty.h"

/**
 * handle_mod_stack_too_short_error - handle mul stack error.
 * @line_number: Line Number.
 */
void handle_mod_stack_too_short_error(int line_number)
{
	fprintf(stderr, "L%d: can't mod stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
/**
 * handle_pchar_stack_too_short_error - handle mul stack error.
 * @line_number: Line Number.
 */
void handle_pchar_stack_too_short_error(int line_number)
{
	fprintf(stderr, "L%d: can't pchar stack empty\n", line_number);
	exit(EXIT_FAILURE);
}
