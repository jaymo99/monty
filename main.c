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
		line_count++;
		printf("Line %d: %s", line_count, line);
		free(line);
		line = readline(fp);
	}

	fclose(fp);
	return (EXIT_SUCCESS);
}
