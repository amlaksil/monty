#include "monty.h"

/**
 * open_file - opens file containing Monty byte codes
 * @file_name: name of file to be opened
 *
 */
void open_file(char *file_name)
{
	int file_check;
	FILE *fd;

	if (file_name == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	file_check = access(file_name, R_OK);
	fd = fopen(file_name, "r");
	if (file_check == -1 || fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	read_file(fd);
	fclose(fd);
}
/**
 * read_file - read the content of the file line by line
 * @file_name: file to be read
 *
 */
void read_file(FILE *file_name)
{
	char *buf = NULL;
	size_t n = 0;
	unsigned int line_number = 1;

	while (getline(&buf, &n, file_name) != EOF)
	{
		if (strcmp(buf, "\n") == 0)
			continue;
		parse_line(buf, line_number);
		line_number++;
	}
	free(buf);
}
/**
 * parse_line - tokenize the given line into opcode and value
 * @buf: pointer points to the string to be tokinized
 * @line_number: line number token to be taken
 *
 */
void parse_line(char *buf, unsigned int line_number)
{
	char *value;
	char *opcode;

	/* any additional text after the opcode is not taken into account */
	opcode = strtok(buf, " \n");
	value = strtok(NULL, " \n");

	if (opcode[0] == '#')
		return; /* return (nop) */
	/*if (strcmp(opcode, "\n") == 0)
		return;*/
	printf("opcode = %s, value = %s\n", opcode, value);
	find_right_func(opcode, value, line_number);
}
/**
 * find_right_func - finds the right fuction that should be called
 * @opcode: command to be excuted
 * @val: the value to be add to the list
 * @ln: line number
 *
 */
void find_right_func(char *opcode, char *val, unsigned int ln)
{
	int i = 0, set = 0;

	instruction_t ops[] = {
		{"push", push_to_stack},
		{"pall", print_element},
		{NULL, NULL}
	};

	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, opcode) == 0)
		{
			check_opcode(ops[i].f, opcode, val, ln);
			set = 1;
		}
		i++;
	}

	if (set != 1)
	{
		dprintf(2, "L %d: unknown instruction %s\n", ln, opcode);
		exit(EXIT_FAILURE);
	}
}
/**
 * check_opcode - checks if opcode is push and val is integer
 * @f: function to be called
 * @op: opcode
 * @val: value should be integer type
 * @ln: line number
 *
 */
void check_opcode(op_func f, char *op, char *val, unsigned int ln)
{
	stack_t *new;
	int flag = 1, i;

	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
		{
			dprintf(2, "L %d: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}

		while (val[i] != '\0')
		{
			if (isdigit(val[i]) == 0)
			{
				dprintf(2, "L %d: usage: push integer\n",
					ln);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		new = create_list(atoi(val) * flag);
		f(&new, ln);
	}
	else
	{
		f(&head, ln);
	}
}
