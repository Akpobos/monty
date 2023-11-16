#include "monty.h"

/**
 * swap - swap top two
 * @stack: the list
 * @line_number: Current line in monty file
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_stack(stack);
		hndlerr("can't swap, stack too short", NULL, line_number);
	}

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	(*stack)->prev = tmp->prev;
	tmp->next = *stack;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add - add top two
 * @stack: the list
 * @line_number: Current line in monty file
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_stack(stack);
		hndlerr("can't add, stack too short", NULL, line_number);
	}
	result = (*stack)->next->n + (*stack)->n;
	(*stack)->next->n = result;
	(*stack)->next->prev = NULL;
	tmp = (*stack);
	*stack = tmp->next;
	free(tmp);
}

/**
 * sub - subtrack top two
 * @stack: the list
 * @line_number: Current line in monty file
 * Return: Nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_stack(stack);
		hndlerr("can't sub, stack too short", NULL, line_number);
	}
	result = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = result;
	(*stack)->next->prev = NULL;
	tmp = (*stack);
	*stack = tmp->next;
	free(tmp);
}
