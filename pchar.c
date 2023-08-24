#include "monty.h"
/**
 * _pchar - prints the char
 * @head: head pointer
 * @counter: line_number
*/
void _pchar(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		clean_up(head);
	}
	if ((*head)->n > 127 || (*head)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		clean_up(head);
	}
	printf("%c\n", (*head)->n);
}
