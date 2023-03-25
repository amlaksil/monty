#include "monty.h"

/**
 * eval - evaluate operation
 * @line: line of input to parse
 * @h: head of doubly linked list
 * @t: tail of doubly linked list
 * @mode: operation mode stack or queue
 * @ln: line number being evaluated
 */
void eval(char *line, stack_t **h, stack_t **t, int *mode, unsigned int ln)
{
	data_t arg;

	arg.mode = mode;
	arg.line_number = ln;
	arg.head = h;
	arg.tail = t;

	/* if the token is the right opcode perform operation */
	if (parse(line, &arg))
		run(&arg);
}
/**
 * parse - parses line of input into tokens
 * @line: line of input to parse
 * @args: arguments to send fo function
 *
 * Return: 0 if opcode is not right one
 * 1 if the opcode is the right monty command
 */
int parse(char *line, data_t *args)
{
	char delims[] = " \t\r\n";
	char *op, *val;
	int i = 0, flag = 1;
	unsigned int ln = args->line_number;

	if (line == NULL)
		return (0);
	op = strtok(line, delims);
	if (op == NULL || op[0] == '#')
		return (0);
	if (strcmp(op, "push") == 0)
	{
		val = strtok(NULL, delims);
		if (val == NULL)
		{
			dprintf(2, "L%d: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
		if (val[0] == '-')
			val = val + 1, flag = -1;
		while (val[i])
		{
			if (isdigit(val[i]) == 0)
			{
				dprintf(2, "L%d: usage: push integer\n", ln);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		args->value = (flag * atoi(val));
		args->op = op;
	}
	args->op = op;
	return (1);
}
/**
 * run - run's specified function based on the opcode
 * @arg: arguments to be passed to function
 *
 */
void run(data_t *arg)
{
	int i = 0;
	instruction_t funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"stack", stack_mode},
		{"queue", queue_mode},
		{NULL, NULL}
	};

	while (funcs[i].opcode)
	{
		if (strcmp(funcs[i].opcode, arg->op) == 0)
		{
			funcs[i].f(arg);
			return;
		}
		i++;
	}

	dprintf(2, "L%d: unknown instruction %s\n", arg->line_number, arg->op);
	exit(EXIT_FAILURE);
}
