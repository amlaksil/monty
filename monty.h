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

/**
 * struct data_s - a struct contails all the neccessary data
 * @op: given opcode
 * @value: value to be inserted to the list
 * @mode: mode of operation stack or queue
 * @line_number: line number in the file at which operation being performed
 * @head: points to the first element on the list
 * @tail: points to the last element of the list
 */
typedef struct data_s
{
	char *op;
	int value;
	int *mode;
	unsigned int line_number;
	stack_t **head;
	stack_t **tail;
} data_t;

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
	void (*f)(data_t *);
} instruction_t;


void free_list(stack_t *);
void eval(char *, stack_t **, stack_t **, int *, unsigned int);
int parse(char *, data_t *);
void run(data_t *);

/* opcode instruction */
void push(data_t *);
void pall(data_t *);
void pint(data_t *);
void pop(data_t *);
void swap(data_t *);
void _add(data_t *);
void _nop(data_t *);
void _sub(data_t *);
void _div(data_t *);
void _mul(data_t *);
void _mod(data_t *);
void stack_mode(data_t *);
void queue_mode(data_t *);

#endif /* __MONTY__ */
