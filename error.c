#include "monty.h"

/**
 * hndlerr - Handle errors
 * @msg: Erro message
 * @file: File name
 * @ln: line number
 * Return: Exit
 */
int hndlerr(char *msg, char *file, unsigned int ln)
{
	if (ln)
		fprintf(stderr, "L%d: ", ln);
	fprintf(stderr, "%s", msg);
	if (file)
		fprintf(stderr, " %s", file);
	fprintf(stderr, "\n");
	exit(EXIT_FAILURE);
}
