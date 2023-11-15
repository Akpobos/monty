#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: the list
 * @line_number: Current line in monty file
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;

	if (!validate_input())
	{
		free_stack(stack);
		hndlerr("usage: push integer", NULL, line_number);
	}
	new = malloc(sizeof(*new));
	if (new == NULL)
		hndlerr("Error: malloc failed", NULL, 0);
	new->n = atoi(input);
	new->next = NULL;
	new->prev = NULL;
	if ((*stack) == NULL)
		*stack = new;
	else
	{
		(*stack)->prev = new;
		new->next = *stack;
		*stack = new;
	}
}

/**
 * pint - prints top of the stack
 * @stack: the list
 * @line_number: Current line in monty file
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		hndlerr("can't pint, stack empty", NULL, line_number);
	printf("%d\n", (*stack)->n);
}

/**
 * pall - prints all the values on the stack
 * @stack: the list
 * @line_number: Current line in monty file
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		pall(&(*stack)->next, line_number);
	}
}
