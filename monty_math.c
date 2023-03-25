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

/**
 * sub - subtracts the top element of the stack from the second top element
 * of the stack.
 *
 * @stack: double pointer to the head/top of a stack
 * @line_number: line number of the command in bytecode file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		clean_all();
		exit(EXIT_FAILURE);
	}
	top = *stack;
	second = top->next;

	second->n -= top->n;
	pop(stack, line_number);
}

/**
 * divide - divides the second top element of the stack by the top element
 * of the stack.
 *
 * @stack: double pointer to the head/top of a stack
 * @line_number: line number of the command in bytecode file
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		clean_all();
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;
	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		clean_all();
		exit(EXIT_FAILURE);
	}

	second->n /= top->n;
	pop(stack, line_number);
}

/**
 * multiply - multiplies the second top element of the stack with the
 * top element of the stack.
 *
 * @stack: double pointer to the head/top of a stack
 * @line_number: line number of the command in bytecode file
 */
void multiply(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		clean_all();
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	second->n *= top->n;
	pop(stack, line_number);
}
/**
 * modulo - computes the remainder of the division of the second top element
 * of the stack by the top element of the stack.
 *
 * @stack: double pointer to the head/top of a stack
 * @line_number: line number of the command in bytecode file
 */
void modulo(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		clean_all();
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;
	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		clean_all();
		exit(EXIT_FAILURE);
	}

	second->n %= top->n;
	pop(stack, line_number);
}
