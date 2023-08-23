#include "monty.h"
/**
 * _pop - removes the top
 * @head: head pointer
 * @counter: line_number
*/
void _pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		clean_up(head);
	}
	h = *head;
	*head = h->next;
	free(h);
}

