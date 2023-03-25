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
	void (*f)(data_t *arg);
} instruction_t;


void free_list(stack_t *head);
void eval(char *line, stack_t **h, stack_t **t, int *mode, unsigned int ln);
int parse(char *line, data_t *arg);
void run(data_t *arg);
void push(data_t *arg);
void pall(data_t *arg);
void pint(data_t *arg);
void pop(data_t *arg);
void swap(data_t *arg);
void stack_mode(data_t *arg);
void queue_mode(data_t *arg);

#endif /* __MONTY__ */
