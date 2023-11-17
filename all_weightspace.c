#include "monty.h"

/**
 * all_weightspace - check space or not.
 * @line: input line
 * Return: (1) success, otherwise(0)
 */
int all_weightspace(const char *line)
{
	while (*line != '\0')
	{
		if (!isspace(*line))
		{
			return (0);
		}
		line++;
	}
	return (1);
}
