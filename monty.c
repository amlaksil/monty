#include "monty.h"
stack_t *head = NULL;

/**
 * main - checks the code
 * @ac: number of argument
 * @argv: list of argument
 *
 * Return: Always zero
 */
int main(int ac, char **argv)
{

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_list();

	return (0);
}
/**
 * free_list - free stack_t list
 *
 */
void free_list(void)
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
 * create_list - creates new list
 * @c: number to be inserted to list
 *
 * Return: the address of the new list
 */
stack_t *create_list(int c)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = c;
	new->next = NULL;
	new->prev = NULL;

	return (new);
}
