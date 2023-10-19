#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<sys/types.h>
#include <string.h>

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
extern unsigned int line_number;


/* fucntions that read the content of the file*/
int read_file(FILE *fpc, stack_t **top);
int token_line(char *line, stack_t **top);
instruction_t *init_ops(void);

/* stack fucntions*/
void push_element(stack_t **top, unsigned int value);
void print_stack(stack_t **top, unsigned int value);
void print_top(stack_t **top, unsigned int value);
void pop_element(stack_t **top, unsigned int value);
void swap_element(stack_t **top, unsigned int value);
void nop_element(stack_t **top, unsigned int value);
void free_stack(stack_t *top);

/* operation functions*/
void op_add(stack_t **top, unsigned int line_number);
void op_sub(stack_t **top, unsigned int line_number);
void op_mul(stack_t **top, unsigned int value);
void op_div(stack_t **top, unsigned int value);



#endif
