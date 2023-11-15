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
 * Return: boolean
 */
int validate_input(void)
{
	unsigned int i = 0;
	bool isvalid = true;

	if (input == NULL)
		return (false);
	if (input[0] == '-')
		i++;
	for (; i < strlen(input); i++)
	{
		if (input[i] < 48 || input[i] > 57)
		{
			isvalid = false;
			break;
		}
	}
	return (isvalid);
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
