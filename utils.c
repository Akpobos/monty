#include "monty.h"

/**
 * endswith - Checks if a string endes with a substring
 * @str: The string
 * @end: The substring
 * Return: True or False
 */
int endswith(char *str, char *end)
{
	int str_length = strlen(str);
	int end_length = strlen(end);
	int i;

	if (end_length > str_length)
		return (false);
	for (i = 0; i < end_length; i++)
	{
		if (str[str_length - i] != end[end_length - i])
			return (false);
	}
	return (true);
}

/**
 * validate_input - Validates the input
 * @line_number: The line number
 * Return: Nothing
 */
void validate_input(unsigned int line_number)
{
	unsigned int i;

	if (input == NULL)
		hndlerr("usage: push integer", NULL, line_number);
	for (i = 0; i < strlen(input); i++)
	{
		if (input[i] < 48 || input[i] > 57)
			hndlerr("usage: push integer", NULL, line_number);
	}
}

/**
 * free_stack - frees list
 * @stack: The list
 * Return: Nothing
 */
void free_stack(stack_t **stack)
{
	if (*stack != NULL)
	{
		free_stack(&(*stack)->next);
		free(*stack);
		*stack = NULL;
	}
}
