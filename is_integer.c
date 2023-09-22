#include "monty.h"
#include <stddef.h>

/**
 * is_integer - Checks if a string is a valid integer.
 * @str: The string to check.
 * Return: 1 if it's a valid integer, 0 otherwise.
 */
int is_integer(char *str)
{
	int i;

	if (str == NULL || *str == '\0')
		return (0);

	i = 0;

	if (str[0] == '-')
		i = 1;

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}

