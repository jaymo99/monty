#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * set_queue - switches data representation mode to QUEUE
 *
 * @stack: double pointer to the head/top of a stack
 * @line_number: line number of the command in bytecode file
 */
void set_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	if (args.flag != QUEUE)
	{
		args.flag = QUEUE;
	}
}

/**
 * set_stack - switches data representation mode to STACK
 *
 * @stack: double pointer to the head/top of a stack
 * @line_number: line number of the command in bytecode file
 */
void set_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	if (args.flag != STACK)
	{
		args.flag = STACK;
	}
}

/**
 * add_to_queue - adds a node at the end of a list (queue)
 *
 * @queue: the queue to add to
 * @node: the node to be added
 * @line_number: line number of the command in bytecode file
 */
void add_to_queue(stack_t **queue, stack_t *node, unsigned int line_number)
{
	stack_t *bottom;

	if (queue == NULL)
	{
		fprintf(stderr, "L%u: can't add_to_queue, null queue\n", line_number);
		clean_all();
		exit(EXIT_FAILURE);
	}

	if (node == NULL)
	{
		fprintf(stderr, "L%u: can't add_to_queue, no node created\n",
				line_number);
		clean_all();
		exit(EXIT_FAILURE);
	}

	bottom = *queue;
	if (bottom == NULL)
	{
		*queue = node;
	}
	else
	{
		while (bottom->next != NULL)
		{
			bottom = bottom->next;
		}
		node->prev = bottom;
		bottom->next = node;
	}
}
