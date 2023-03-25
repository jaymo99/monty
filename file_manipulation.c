#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

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
