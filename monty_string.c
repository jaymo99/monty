#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * pchar - prints the char at the top of the stack followed by newline.
 *
 * @stack: double pointer to the head/top of a stack
 * @line_number: line number of the command in bytecode file
 *
 * Description: Integer stored at the top of the stack is treated as the
 * ASCII value of the character to be printed.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		clean_all();
		exit(EXIT_FAILURE);
	}

	top = *stack;
	if (top->n < 0 || top->n > 127) /* exceeds ASCII range */
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		clean_all();
		exit(EXIT_FAILURE);
	}

	putchar(top->n);
	putchar('\n');
}