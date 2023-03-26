#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * The integer stored at the top of the stack is treated as the ascii
 * value of the character to be printed
 *
 * @arg: points arguments in data_t struct
 */
void pchar(data_t *arg)
{
	stack_t *h = *arg->head;
	int n = h->n;

	if (h == NULL)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", arg->line_number);
		exit(EXIT_FAILURE);
	}

	if (n >= 0 && n < 127)
		printf("%c\n", n);
	else
	{
		dprintf(2, "L%d: can't pchar, value out of range\n",
			arg->line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * pstr - prints the string starting at the top of the stack
 * The integer stored in each element of the stack is treated
 * as the ascii value of the character to be printed.
 * If the stack is empty, print only a new line
 *
 * @arg: points arguments in data_t struct
 */
void pstr(data_t *arg)
{
	stack_t *h = *arg->head;

	while (h)
	{
		if (h->n < 0 || h->n > 127 || h->n == 0)
			return;
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
/**
 * rotl - rotates the stack to the top
 * the top element of the stack becomes the last one, and
 * the second top element of the stack becomes the first one
 * It never fails
 * @arg: points argument in data_t struct
 */
void rotl(data_t *arg)
{
	stack_t **h = arg->head;
	stack_t *tmp = *h;
	stack_t *top_node;

	if (tmp->next != NULL)
	{
		top_node = tmp; /* store the address of the first node */
		*h = tmp->next;  /* make the list begin at the second node */
		(*h)->prev = NULL;
		while (tmp->next != NULL)
			tmp = tmp->next;
		top_node->next = NULL;
		/* make the last node points to the top_node */
		tmp->next = top_node;
		top_node->prev = tmp;
	}
}
/**
 * rotr - rotates the stack to the bottom
 * the last element of the stack becomes the top element
 * rotr never fails
 * @arg: points argument in data_t struct
 */
void rotr(data_t *arg)
{
	stack_t **h = arg->head;
	stack_t *tmp = *h;
	stack_t *bottom_node;

	if (tmp->next != NULL)
	{
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		bottom_node = tmp->next;
		/**
		 * terminate the node before the very last node so it will
		 * become easy to make the last node be the first node
		 */
		tmp->next = NULL;
		bottom_node->prev = NULL;
		/* make the last node be the first node in the list */
		bottom_node->next = *h;
		*h = bottom_node;
	}
}
