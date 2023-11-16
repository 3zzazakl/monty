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

			else
				handle_invalid_instruction(opcode, line_number);
		}
		line_number++;
	}
		free_stack(stack);
		fclose(file);
		free(line);
		return (0);
}
