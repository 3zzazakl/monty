#include "monty.h"

/**
 * handle_invalid_instruction - check invalid instruction
 * @instruction: input
 * @line_number: line number.
 */
void handle_invalid_instruction(const char *instruction, int line_number)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruction);
	exit(EXIT_FAILURE);
}

/**
 * handle_push_integer_error - handle push errors
 * @line_number: line number
 */
void handle_push_integer_error(int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}
