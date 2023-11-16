#include "monty.h"

/**
 * _mod - mod top two
 * @stack: the list
 * @line_number: Current line in monty file
 * Return: Nothing
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	int result;

	if (
			*stack == NULL ||
			(*stack)->next == NULL ||
			(*stack)->n == 0
			)
	{
		if (*stack != NULL && (*stack)->n == 0)
		{
			free_stack(stack);
			hndlerr("division by zero", NULL, line_number);
		}
		else
		{
			free_stack(stack);
			hndlerr("can't mod, stack too short", NULL, line_number);
		}
	}
	result = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = result;
	(*stack)->next->prev = NULL;
	tmp = (*stack);
	*stack = tmp->next;
	free(tmp);
}

/**
 * _pchar - prints the char at the top of the stack
 * @stack: the list
 * @line_number: Current line in monty file
 * Return: Nothing
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		free_stack(stack);
		hndlerr("can't pchar, stack empty", NULL, line_number);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		free_stack(stack);
		hndlerr("can't pchar, value out of range", NULL, line_number);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * _pstr - prints the string starting at the top of the stack
 * @stack: the list
 * @line_number: Current line in monty file
 * Return: Nothing
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	if (
			(*stack) == NULL ||
			(*stack)->n <= 0 ||
			(*stack)->n > 127
	   )
	{
		putchar('\n');
		return;
	}

	putchar((*stack)->n);
	_pstr(&(*stack)->next, line_number);
}

/**
 * _rotl - swap top two
 * @stack: the list
 * @line_number: Current line in monty file
 * Return: Nothing
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (tmp->next)
		tmp = tmp->next;
	(*stack)->next->prev = NULL;
	(*stack)->prev = tmp;
	tmp->next = *stack;
	*stack = (*stack)->next;
	tmp->next->next = NULL;
}

/**
 * _rotr - rotate stack
 * @stack: the list
 * @line_number: Current line in monty file
 * Return: Nothing
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *copy;

	(void)line_number;

	copy = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (copy->next)
		copy = copy->next;
	copy->next = *stack;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*stack)->prev = copy;
	(*stack) = copy;
}
