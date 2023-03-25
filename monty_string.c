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

/**
 * pstr - prints the string starting at the top of the stack, followed
 * by newline.
 *
 * @stack: double pointer to the head/top of a stack
 * @line_number: line number of the command in bytecode file
 *
 * Description: Integer stored in each element is treated as the ASCII value
 * of the character to be printed.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: can't pstr, null stack\n", line_number);
		clean_all();
		exit(EXIT_FAILURE);
	}

	top = *stack;
	while (top != NULL)
	{
		if (top->n < 1 || top->n > 127) /* ASCII '0' is excluded ('\0') */
		{
			break;
		}
		putchar(top->n);
		top = top->next;
	}
	putchar('\n');
}

/**
 * rotl - rotates the stack to the top
 *
 * @stack: double pointer to the head/top of a stack
 * @line_number: line number of the command in bytecode file
 *
 * Description: the top element of the stack becomes the last one, and the
 * second top element of the stack becomes the first one.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *second;
	stack_t *bottom;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		if (line_number)
		{
			return;
		}
		return;
	}
	top = *stack;
	second = top->next;

	/* remove top element */
	top->next = NULL;
	second->prev = NULL;
	*stack = second;

	/* attach element at the bottom */
	bottom = *stack;
	while (bottom->next != NULL)
	{
		bottom = bottom->next;
	}
	bottom->next = top;
	top->prev = bottom;
}

/**
 * rotr - rotates the stack to the bottom
 *
 * @stack: double pointer to the head/top of a stack
 * @line_number: line number of the command in bytecode file
 *
 * Description: the last element of the stack becomes the top one.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *bottom;
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		if (line_number)
		{
			return;
		}
		return;
	}
	top = *stack;

	/* find bottom element */
	bottom = *stack;
	while (bottom->next != NULL)
	{
		bottom = bottom->next;
	}

	/* Detach bottom elment */
	temp = bottom->prev;
	temp->next = NULL;
	bottom->prev = NULL;

	/* Attach bottom element at the top */
	top->prev = bottom;
	bottom->next = top;
	*stack = bottom;
}
