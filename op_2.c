#include "monty.h"

/**
 * swap - prints top of the stack
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
