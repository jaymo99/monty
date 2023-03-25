#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add - adds the top two elements of the stack
 *
 * @stack: double pointer to the head/top of a stack
 * @line_number: line number of the command in bytecode file
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		clean_all();
		exit(EXIT_FAILURE);
	}
	top = *stack;
	second = top->next;

	second->n += top->n;
	pop(stack, line_number);
}
