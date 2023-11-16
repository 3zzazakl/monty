#include "monty.h"

/**
 * is_integer - checking if input is integer or not.
 * @str: input
 * Return: (1) if it's integer, 0 otherwise.
 */
int is_integer(const char *str)
{
	char *p;

	if (str == NULL || *str == '\0' || isspace(*str))
	{
		return (0);
	}
	strtol(str, &p, 10);
	return (*p == '\0');
}
