#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/* global variable as declared in 'monty.h' */
globals_t args = {NULL, NULL, NULL, NULL, NULL};

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
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	void (*function_pointer)(stack_t **stack, unsigned int line_number);

	args.stack = &stack;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	args.fp = fopen(argv[1], "r");
	if (args.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	args.line = readline(args.fp);
	while (args.line != NULL)
	{
		line_number++;
		function_pointer = get_cmd(args.line);
		if (function_pointer == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
					line_number, args.opcode);
			clean_all();
			exit(EXIT_FAILURE);
		}
		function_pointer(&stack, line_number);
		free(args.line);
		args.line = readline(args.fp);
	}
	clean_all();
	return (EXIT_SUCCESS);
}
