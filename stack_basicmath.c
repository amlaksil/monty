#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * and the result is stored in the second top element of the stack
 * @arg: points to data_t struct
 */
void _add(data_t *arg)
{
	stack_t **h = arg->head;
	stack_t *tmp;
	int fnum, snum;

	if (*h == NULL || h == NULL || (*h)->next == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n",
			arg->line_number);
		exit(EXIT_FAILURE);
	}
	fnum = (*h)->n;
	tmp = *h;
	*h = (*h)->next;
	snum = (*h)->n;
	(*h)->n = snum + fnum;
	*h = tmp;
}
/**
 * _sub - subtracts the top element of the stack from the second
 * top element of the stack and stores the result in the second
 * top element and the top element is removed
 *
 * @arg: point arguments in data_ t strut
 */
void _sub(data_t *arg)
{
	stack_t **h = arg->head;
	stack_t *tmp;
	int fnum, snum;

	if (*h == NULL || h == NULL || (*h)->next == NULL)
	{
		dprintf(2, "L%d: can't sub, stack too short\n",
			arg->line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *h;
	fnum = (*h)->n;
	*h = (*h)->next;
	snum = (*h)->n;
	(*h)->n = snum - fnum;
	(*h)->prev = NULL;
	free(tmp);
}
/**
 * _div - divides the second top element of the stack by
 * the top element of the stack and the result is stored
 * in the second top element of the stack and the top
 * element is removed.
 * If the top element is 0 print error
 *
 * @arg: point arguments in data_ t strut
 */
void _div(data_t *arg)
{
	stack_t **h = arg->head;
	stack_t *tmp;
	int fnum, snum;

	if (*h == NULL || h == NULL || (*h)->next == NULL)
	{
		dprintf(2, "L%d: can't div, stack too short\n",
			arg->line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *h;
	fnum = (*h)->n;
	*h = (*h)->next;
	snum = (*h)->n;
	(*h)->prev = NULL;
	free(tmp);
	if (fnum == 0)
	{
		dprintf(2, "L%d: division by zero\n", arg->line_number);
		exit(EXIT_FAILURE);
	}
	(*h)->n = snum / fnum;
}
/**
 * _mul - multiplies the second top element of the stack with the
 * top element of the stack. If the stack contains less than two
 * elements print error message and the result is stored in the
 * second element and top element is removed
 *
 * @arg: point arguments in data_ t strut
 */
void _mul(data_t *arg)
{
	stack_t **h = arg->head;
	stack_t *tmp;
	int fnum, snum;

	if (*h == NULL || h == NULL || (*h)->next == NULL)
	{
		dprintf(2, "L%d: can't mul, stack too short\n",
			arg->line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *h;
	fnum = (*h)->n;
	*h = (*h)->next;
	snum = (*h)->n;
	(*h)->n = fnum * snum;
	(*h)->prev = NULL;
	free(tmp);
}

/**
 * _mod - divides the second top element of the stack by
 * the top element of the stack and compute the remainder
 * and the result is stored in the second top element
 * of the stack and the top element is removed.
 * If the top element is 0 print error
 *
 * @arg: point arguments in data_ t strut
 */
void _mod(data_t *arg)
{
	stack_t **h = arg->head;
	stack_t *tmp;
	int fnum, snum;

	if (*h == NULL || h == NULL || (*h)->next == NULL)
	{
		dprintf(2, "L%d: can't mod, stack too short\n",
			arg->line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *h;
	fnum = (*h)->n;
	*h = (*h)->next;
	snum = (*h)->n;
	(*h)->prev = NULL;
	free(tmp);
	if (fnum == 0)
	{
		dprintf(2, "L%d: division by zero\n", arg->line_number);
		exit(EXIT_FAILURE);
	}
	(*h)->n = snum % fnum;
}
