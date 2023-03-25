#ifndef __MONTY__
#define __MONTY__

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

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

extern stack_t *head;

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


typedef void (*op_func)(stack_t **, unsigned int);

void free_list(void);
stack_t *create_list(int c);
void open_file(char *file_name);
void parse_line(char *buf, unsigned int line_number);
void read_file(FILE *file_name);
void push_to_stack(stack_t **new, unsigned int ln);
void print_element(stack_t **head, unsigned int ln);
void check_opcode(op_func f, char *op, char *val, unsigned int ln);
void find_right_func(char *opcode, char *val, unsigned int ln);

#endif /* __MONTY__ */
