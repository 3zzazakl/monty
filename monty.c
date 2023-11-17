#include "monty.h"
/**
 * main - main function for monty project.
 * @argc: input arguments.
 * @argv: array of elements.
 * Return: (Success) 0
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		char *opcode, *arg;

		opcode = strtok(line, " \n");
		if (*line == '#')
			continue;
		if (opcode != NULL)
		{
			if (strcmp(opcode, "push") == 0)
			{
				arg = strtok(NULL, " \n");
				if (arg == NULL || !is_integer(arg))
						handle_push_integer_error(line_number);
				push(&stack, atoi(arg));
			}
			else if (strcmp(opcode, "pall") == 0)
				pall(stack);
			else if (strcmp(opcode, "pint") == 0)
			{
				if (stack == NULL)
					handle_pint_empty_stack_error(line_number);
				else
					pint(stack);
			}
			else if (strcmp(opcode, "pop") == 0)
			{
				if (stack == NULL)
					handle_pop_empty_stack_error(line_number);
				else
					pop(&stack);
			}
			else if (strcmp(opcode, "swap") == 0)
			{
				if (stack == NULL || stack->next == NULL)
					handle_swap_stack_too_short_error(line_number);
				else
					swap(&stack, line_number);
			}
			else if (strcmp(opcode, "add") == 0)
			{
				if (stack == NULL || stack->next == NULL)
					handle_add_stack_too_short(line_number);
				else
					add(&stack);
			}
			else if (strcmp(opcode, "nop") == 0)
			{
				/*No Operation required*/
			}
			else if (strcmp(opcode, "sub") == 0)
			{
				if (stack == NULL || stack->next == NULL)
					handle_sub_stack_too_short_error(line_number);
				else
					swap(&stack, line_number);
			}
			else if (strcmp(opcode, "div") == 0)
			{
				if (stack == NULL || stack->next == NULL)
					handle_div_stack_too_short_error(line_number);
				else if (stack->n == 0)
					handle_division_by_zero(line_number);
				else
					_div(&stack);
			}
			else if (strcmp(opcode, "mul") == 0)
			{
				if (stack == NULL || stack->next == NULL)
					handle_mul_stack_too_short_error(line_number);
				else
					mul(&stack);
			}
			else if (strcmp(opcode, "mod") == 0)
			{
				if (stack == NULL || stack->next == NULL)
					handle_mod_stack_too_short_error(line_number);
				else if (stack->n == 0)
					handle_division_by_zero(line_number);
				else
					mod(&stack);
			}
			else if (strcmp(opcode, "pchar") == 0)
			{
				if (stack == NULL)
					handle_pchar_stack_too_short_error(line_number);
				else
					pchar(&stack, line_number);
			}
			else if (strcmp(opcode, "pstr") == 0)
				pstr(&stack, line_number);
			else if (strcmp(opcode, "rotl") == 0)
				rotl(&stack, line_number);
			else if (strcmp(opcode, "rotr") == 0)
				rotr(&stack, line_number);
			else
				handle_invalid_instruction(opcode, line_number);
		}

		line_number++;
	}
	fclose(file);
	free(line);
	free_stack(stack);
	return (0);
}
