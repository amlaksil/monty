#include "monty.h"

/**
 * push_to_stack - pushes element to the stack
 * @new: the address of the new node to be added
 * @ln: line number
 *
 */
void push_to_stack(stack_t **new, unsigned int ln)
{
	stack_t *ptr;
	(void)ln;

	if (head == NULL)
	{
		head = *new;
		return;
	}
	ptr = head;
	head = *new;
	head->next = ptr;
	ptr->prev = head;
}
/**
 * print_element - print elements in the list
 * @head: pointer points to the first element in the list
 * @ln: line number
 */
void print_element(stack_t **head, unsigned int ln)
{
	stack_t *ptr = *head;
	(void)ln;

	if (ptr == NULL)
		return;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
