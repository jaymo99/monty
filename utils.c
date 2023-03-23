#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * check_opvalue - validates the argument/value passed after opcode
 *
 * @line_number: line of the command in bytecode file
 *
 * Return: the integer value.
 */
int check_opvalue(unsigned int line_number)
{
	int num;

	/* args is a global value declared in 'monty.h' */
	if (args.opvalue != NULL)
	{
		num = atoi(args.opvalue);
		if (num == 0 && args.opvalue[0] != '0')
		{
			fprintf(stderr, "L<%u>: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L<%u>: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	return (num);
}

/**
 * free_stack - frees all nodes in a stack.
 *
 * @stack: double pointer to stack.
 */
void free_stack(stack_t **stack)
{
	stack_t *top;
	stack_t *temp;

	if (stack != NULL)
	{
		top = *stack;
		while (top != NULL)
		{
			temp = top->next;
			free(top);
			top = temp;
		}
	}
}
