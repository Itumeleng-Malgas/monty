#include "monty.h"
/**
 * _div - divides the top two elements
 * @head: head pointer
 * @counter: line_number
*/
void _div(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int length = 0, current;

	h = *head;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		clean_up(head);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		clean_up(head);
	}
	current = h->next->n / h->n;
	h->next->n = current;
	*head = h->next;
	free(h);
}
