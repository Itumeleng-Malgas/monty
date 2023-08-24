#include "monty.h"
/**
 * _pchar - prints the char
 * @head: head pointer
 * @counter: line_number
*/
void _pchar(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;

	if (h == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		clean_up(head);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		clean_up(head);
	}
	printf("%c\n", h->n);
}
