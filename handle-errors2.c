#include "monty.h"
/**
 * handle_add_stack_too_short - handle add stack
 * @line_number: Line Number
 */
void handle_add_stack_too_short(int line_number)
{
	fprintf(stderr, "L%d: can't add stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
/**
 * handle_sub_stack_too_short_error - handle sub stack error.
 * @line_number: Line number
 */
void handle_sub_stack_too_short_error(int line_number)
{
	fprintf(stderr, "L%d: can't sub stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * handle_div_stack_too_short_error - handle div stack error.
 * @line_number: Line Number.
 */
void handle_div_stack_too_short_error(int line_number)
{
	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * handle_division_by_zero - handle divide by zero errro
 * @line_number: Line Number
 */
void handle_division_by_zero(int line_number)
{
	fprintf(stderr, "L%d: division by zero\n", line_number);
	exit(EXIT_FAILURE);
}
/**
 * handle_mul_stack_too_short_error - handle mul stack error.
 * @line_number: Line Number.
 */
void handle_mul_stack_too_short_error(int line_number)
{
	fprintf(stderr, "L%d: can't mul stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
