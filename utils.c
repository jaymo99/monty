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
	if (args.opvalue != NULL && is_integer(args.opvalue))
	{
		num = atoi(args.opvalue);
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		clean_all();
		exit(EXIT_FAILURE);
	}
	return (num);
}

/**
 * is_integer - checks if a string represents a numerical value (integer).
 *
 * @str: string representation
 * Description: the function checks if all characters are digits.
 * a '-' is allowed only in the first position, to symbolize negative values.
 *
 * Return: 1 if the representation is an integer, 0 otherwise.
 */
unsigned int is_integer(char *str)
{
	unsigned int i = 0;

	while (str != NULL && str[i] != '\0')
	{
		if (str[i] == '-' && i == 0)
		{
			i++;
			continue;
		}

		/* ascii values for '0' to '9' */
		if (str[i] < 48 || str[i] > 57)
		{
			return (0);
		}
		i++;
	}
	return (1);
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

/**
 * clean_all - frees current line, stack and closes open file
 *
 * Description: cleans up resources before program termination
 */
void clean_all(void)
{
	if (args.line != NULL)
	{
		free(args.line);
	}
	free_stack(args.stack);
	if (args.fp != NULL)
	{
		fclose(args.fp);
	}
}

/**
 * nop - This function does nothing. It's a blank opcode
 *
 * @stack: double pointer to the head/top of a stack
 * @line_number: line of the command in bytecode file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	if (stack || !stack || line_number || !line_number)
	{
		return;
	}
}
