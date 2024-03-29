#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct info_s - Variables -arg, file, line, is_queue
 * @arg: value
 * @file: pointer to monty file
 * @line: line content
 * @is_queue: flag change stack <-> queue
 * Description: carries info throughout the program
 */
typedef struct info_s
{
	char *arg;
	FILE *file;
	char *line;
	bool is_queue;
} info_t;

extern info_t info;

#define INFO_INIT {NULL, NULL, NULL, false}

/* errors_1.c */
void push_error(stack_t **stack, unsigned int line_number);
void opcode_error(stack_t **stack, unsigned int counter, char *op);
void pint_error(stack_t **stack, unsigned int line_number);
void pop_error(stack_t **stack, unsigned int line_number);
void div_by_zero_error(stack_t **stack, unsigned int line_number);

/* errors_2.c */
void swap_error(stack_t **stack, unsigned int line_number);
void add_error(stack_t **stack, unsigned int line_number);
void sub_error(stack_t **stack, unsigned int line_number);
void div_error(stack_t **stack, unsigned int line_number);
void mul_error(stack_t **stack, unsigned int line_number);

/* errors_3.c */
void mod_error(stack_t **stack, unsigned int line_number);
void pchar_error(stack_t **stack, unsigned int line_number);
void pchar_out_of_range_error(stack_t **stack, unsigned int line_number);
void usage_error(void);
void file_open_error(char *filename);

/* opcode_1.c */
void push(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/* opcode_2.c */
void add(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);

/* opcode_3.c */
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/* opcode_4.c */
void add_to_stack(stack_t **head, int n);
void add_to_queue(stack_t **head, int n);
void f_stack(stack_t **head, unsigned int counter);
void f_queue(stack_t **head, unsigned int counter);

/* execute.c */
int execute(stack_t **stack, unsigned int counter);

/* memory.c */
void free_stack(stack_t *head);

#endif /* MONTY_H */

