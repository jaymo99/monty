#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * readline - reads a single line in an open file
 *
 * @fp: file pointer
 *
 * Description: End of line is symbolized by '\n'
 *
 * Return: an array of characters (a string) representing the line.
 * OR: NULL on error.
 */
char *readline(FILE *fp)
{
	int len = 0;
	char *line = NULL;

	if (fp == NULL)
	{
		return (NULL);
	}

	len = linelen(fp);
	if (len > 0)
	{
		line = malloc(sizeof(char) * len + 1);
		if (line == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			clean_all();
			exit(EXIT_FAILURE);
		}

		if (fgets(line, len + 1, fp) == NULL)
		{
			fprintf(stderr, "readline error: fgets() failed\n");
			clean_all();
			exit(EXIT_FAILURE);
		}
	}

	return (line);
}

/**
 * linelen - finds the length of current line in an open file
 *
 * @fp: FILE pointer
 *
 * Description: End of line is symbolized by '\n' which is also included
 * in the line length.
 *
 * Return: length of line
 */
int linelen(FILE *fp)
{
	long int pos;
	int c, len = 0;

	pos = ftell(fp); /* current file position */
	if (pos == -1)
	{
		fprintf(stderr, "linelen error: ftell() failed\n");
		clean_all();
		exit(EXIT_FAILURE);
	}

	/* determine length of line */
	c = fgetc(fp);
	if (c == EOF)
	{
		return (0);
	}
	while (c != EOF)
	{
		len++;
		if (c == '\n')
		{
			break;
		}
		c = fgetc(fp);
	}

	/* Move the file pointer back to the beginning of line */
	if (fseek(fp, pos, SEEK_SET) != 0)
	{
		fprintf(stderr, "readline error: fseek() failed\n");
		clean_all();
		exit(EXIT_FAILURE);
	}

	return (len);
}

/**
 * get_cmd - finds the function to execute a specified command
 *
 * @str: text string bearing the command.
 *
 * Return: A function pointer, or NULL if command is invalid
 */
void (*get_cmd(char *str))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	char *opcode;

	instruction_t cmds[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", nop},
		{"nop", nop},
		{NULL, NULL}
	};

	/* 'args' is global variable*/
	args.opcode = strtok(str, " \t\n"); /* delimter space, tab or newline */
	opcode = args.opcode;
	i = 0;
	if (opcode == NULL)
	{
		return (nop);
	}
	while (cmds[i].opcode != NULL)
	{
		if (strcmp(opcode, cmds[i].opcode) == 0)
		{
			args.opvalue = strtok(NULL, " \t\n");
			return (cmds[i].f);
		}
		i++;
	}
	return (NULL);
}

