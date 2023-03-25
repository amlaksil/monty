#include "monty.h"

/**
 * push - adds a new node at the beginning of a stack_t list,
 * or in queue mode, add node to end
 *
 * @arg: points to arguments in data_t struct
 *
 */
void push(data_t *arg)
{
	stack_t **h = arg->head;
	stack_t *new = NULL;
	stack_t *temp = NULL;

	if (h == NULL)
	{
		dprintf(2, "L%d: usage: push integer\n", arg->line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = arg->value;
	new->prev = NULL;
	new->next = NULL;

	if (*h == NULL)
	{
		*h = new;  /* If the list is empty */
		return;
	}
	if (*arg->mode == 1)
	{
		temp = *h;

		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
		return;
	}
	/* stack mode */

	(*h)->prev = new;
	new->next = *h;
	*h = new;
}
/**
 * pall - prints all in the list data_t starting from the top
 * @arg:  points to arguments in data_t struct
 */
void pall(data_t *arg)
{
	stack_t *h = *arg->head;

	if (h == NULL)
		return;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
/**
 * pop - remove's the top element in the list
 * @arg: points to arguments in data_t struct
 */

void pop(data_t *arg)
{
	stack_t **h = arg->head;
	stack_t *current = NULL;

	if (*h == NULL || h == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", arg->line_number);
		exit(EXIT_FAILURE);
	}
	current = *h;
	*h = (*h)->next;
	if (*h != NULL)
		(*h)->prev = NULL;
	free(current);
}
/**
 * pint - prints the value at the top of the stack
 * @arg: points to arguments in data_t struct
 */
void pint(data_t *arg)
{
	stack_t *h = *arg->head;

	if (h == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", arg->line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", h->n);
}
/**
 * swap - swaps the top two elements of the stack
 * @arg: points to arguments in data_t struct
 */
void swap(data_t *arg)
{
	stack_t **h = arg->head;
	stack_t *tmp;
	int fnum, snum;

	if (*h == NULL || h == NULL || (*h)->next == NULL)
	{
		dprintf(2, "L%d: can't swap, stack too short\n",
			arg->line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *h;
	fnum = (*h)->n;
	*h = (*h)->next;
	snum = (*h)->n;
	(*h)->n = fnum;
	*h = tmp;
	(*h)->n = snum;
}
