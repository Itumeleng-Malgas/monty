#include "monty.h"
/**
 * _pint - prints the top
 * @head: head pointer
 * @counter: line_number
*/
void _pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		clean_up(head);
	}
	printf("%d\n", (*head)->n);
}
