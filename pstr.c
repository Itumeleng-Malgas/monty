#include "monty.h"
/**
 * _pstr - prints the string
 * @head: head pointer
 * @counter: line_number
*/
void _pstr(stack_t **head, unsigned int counter __attribute__((unused)))
{
	stack_t *h = *head;

	while (h)
	{
		if (h->n)
		{
			if (h->n > 127 || h->n <= 0)
				break;
			printf("%c", h->n);
			h = h->next;
		}
	}
	printf("\n");
}
