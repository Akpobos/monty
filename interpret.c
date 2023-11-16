#include "monty.h"

/**
 * interpret - process and run the monty instructions
 * @stack: Points to pointer to stack
 * @line: Current instruction
 * @ln: current line number
 * Return: Nothing
 */
char *input;
void interpret(stack_t **stack, char *line, unsigned int ln)
{
	char *op = strtok(line, TOK_DEL);
	unsigned int i;
	void (*f)(stack_t **stack, unsigned int ln) = NULL;
	instruction_t ops[] = {
		{ "push", push }, { "pint", pint }, { "pall", pall },
		{ "pop", pop }, { "nop", nop }, { "swap", swap },
		{ "add", add }, { "sub", sub }, {"div", _div},
		{ "mul", _mul }, { "mod", _mod }, { "pchar", _pchar },
		{ "pstr", _pstr }, { "rotl", _rotl },
		{ NULL, NULL }
	};

	if (op == NULL || op[0] == '#')
		return;
	input = strtok(NULL, TOK_DEL);
	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(ops[i].opcode, op) == 0)
		{
			f = ops[i].f;
			break;
		}
	}

	if (f == NULL)
		hndlerr("unknown instruction", op, ln);
	f(stack, ln);
}
