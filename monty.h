#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>


/* DATA STRUCTURES */
/* =============== */


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct globals = global variables.
 * @opcode: the opcode
 * @oparg: argument value passed to opcode
 */
typedef struct globals_s
{
	char *opcode;
	char *opvalue;
} globals_t;

/* declaration for global variable of type 'globals_t */
extern globals_t args;

/* FUNCTION PROTOTYPES */
/* =================== */

/* file_manipulation.c */
char *readline(FILE *fp);
int linelen(FILE *fp);
void (*get_cmd(char *str))(stack_t **stack, unsigned int line_number);

/* stack_operations.c */
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

/* utils.c */
int check_opvalue(unsigned int line_number);
void free_stack(stack_t **stack);

#endif /* MONTY_H */
