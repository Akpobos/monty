#include "monty.h"

/**
 * main - Entry file for monty program
 * @argc: Argument count
 * @argv: Argument vector
 * Return: integer
 */

int main(int argc, char **argv)
{
	unsigned int line_number = 0;
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	stack_t *stack = NULL;

	if (argc != 2)
		hndlerr("USAGE: monty file", NULL, line_number);
	if (!endswith(argv[1], ".m"))
		hndlerr("Error: Can't open file", argv[1], line_number);
	stream = fopen(argv[1], "r");
	if (stream == NULL)
		hndlerr("Error: Can't open file", argv[1], line_number);
	while (getline(&line, &len, stream) != -1)
	{
		line_number += 1;
		interpret(&stack, line, line_number);
	}
	free(line);
	line = NULL;
	free_stack(&stack);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
