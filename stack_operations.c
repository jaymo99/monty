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
		fprintf(stderr, "L<%u>: cannot print null stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	if (top != NULL)
	{
		printf("%d\n", top->n);
	}
	else
	{
		fprintf(stderr, "L<%u>: can't pint, stack empty\n", line_number);
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
		fprintf(stderr, "L<%u>: cannot print null stack\n", line_number);
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
