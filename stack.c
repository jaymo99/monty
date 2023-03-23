#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - inserts element at the top of a stack
 *
 * @top: top-most element of stack.
 * @n: integer value
 *
 * Return: top element of the stack.
 */
stack_t *push(stack_t *top, int n)
{
	stack_t *node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = n;
	node->next = top;
	node->prev = NULL;

	if (top == NULL)
	{
		top = node;
	}
	else
	{
		top->prev = node;
		top = node;
	}

	return (top);
}

/**
 * pall - print all items in a stack.
 *
 * @top: top item in the stack
 */
void pall(stack_t *top)
{
	while (top != NULL)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}

/**
 * free_stack - frees all nodes in a stack.
 *
 * @top: top item in the stack.
 */
void free_stack(stack_t *top)
{
	stack_t *temp;

	while (top != NULL)
	{
		temp = top->next;
		free(top);
		top = temp;
	}
}
