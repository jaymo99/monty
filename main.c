#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - main entry point of the program
 * @argc: argument count.
 * @argv: argument vector.
 * Return - Always SUCCESS
 */
int main(int argc, char *argv[])
{
    FILE *fd;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    fd = fopen(argv[1], "r");
    if (fd == NULL)
    {
        fprintf(stderr,"Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    fclose(fd);
	return (EXIT_SUCCESS);
}
