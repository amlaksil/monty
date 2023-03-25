#include "monty.h"


/**
 * main - checks the code
 * @ac: number of argument
 * @argv: list of argument
 *
 * Return: Always zero
 */
int main(int ac, char **argv)
{
	FILE *fd;
	char *line = NULL;
	size_t len = 0;
	stack_t *head = NULL;
	stack_t *tail = NULL;
	int mode = 0;
	unsigned int line_number = 1;

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, fd) != EOF)
	{
		eval(line, &head, &tail, &mode, line_number);
		line_number++;
	}
	fclose(fd);
	free(line);
	free_list(head);

	return (0);
}
/**
 * free_list - free stack_t list
 * @head: points to the first element in the list
 *
 */
void free_list(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * stack_mode - change to stack LIEO format
 *
 * @args: arguments to be passed
 */
void stack_mode(data_t *args)
{
	*args->mode = 0;
}
/**
 * queue_mode - change to queue FIFO format
 *
 * @args: arguments to be passed
 */

void queue_mode(data_t *args)
{
	*args->mode = 1;
}
