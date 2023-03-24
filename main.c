#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/* global variable as declared in 'monty.h' */
globals_t args = {NULL, NULL};

/**
 * main - main entry point of the program
 *
 * @argc: argument count.
 * @argv: argument vector.
 *
 * Return: Always SUCCESS
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char *line;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	void (*function_pointer)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line = readline(fp);
	while (line != NULL)
	{
		line_number++;
		function_pointer = get_cmd(line);
		if (function_pointer == NULL)
		{
			fprintf(stderr, "L<%d>: unknown instruction <%s>\n",
					line_number, args.opcode);
			free(line);
			free_stack(&stack);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		function_pointer(&stack, line_number);
		free(line);
		line = readline(fp);
	}
	fclose(fp);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
