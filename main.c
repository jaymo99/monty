#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

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
	int line_count = 0;
	stack_t *top = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	top = push(top, 1);
	top = push(top, 2);
	top = push(top, 3);
	top = push(top, 4);
	pall(top);
	printf("===============");

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line = readline(fp);
	while (line != NULL)
	{
		line_count++;
		printf("Line %d: %s", line_count, line);
		free(line);
		line = readline(fp);
	}

	fclose(fp);
	free_stack(top);
	return (EXIT_SUCCESS);
}
