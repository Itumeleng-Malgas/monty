#include "monty.h"

/**
 * _pall - prints all elements in the list
 * @head: head pointer
 * @n: counter
*/
void _pall(stack_t **head, unsigned int n __attribute__((unused)))
{
	stack_t *h = *head;

	if (h == NULL)
		return;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
