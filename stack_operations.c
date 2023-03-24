#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - inserts element at the top of a stack
 *
 * @stack: double pointer to the head/top of a stack
 * @line_number: line of the command in bytecode file
 */
void push(stack_t **stack, unsigned int line_number)
{
	int num = check_opvalue(line_number);
	stack_t *node, *top;


	if (stack == NULL)
	{
		fprintf(stderr, "Error: address of stack is NULL\n");
		exit(EXIT_FAILURE);
	}
	top = *stack;

	node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = num;
	node->next = NULL;
	node->prev = NULL;

	if (top == NULL)
	{
		*stack = node;
	}
	else
	{
		top->prev = node;
		node->next = top;
		*stack = node;
	}
}

/**
 * pint - prints the value at the top of the stack
 *
 * @stack: double pointer to the head/top of a stack
 * @line_number: line of the command in bytecode file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: cannot print null stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	if (top != NULL)
	{
		printf("%d\n", top->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - print all items in a stack.
 *
 * @stack: double pointer to the head/top of a stack
 * @line_number: line of the command in bytecode file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: cannot print null stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	while (top != NULL)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}

/**
 * pop - removes the top element of the stack
 *
 * @stack: double pointer to the head/top of a stack
 * @line_number: line of the command in bytecode file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	temp = top->next;
	free(top);
	*stack = temp;
}
