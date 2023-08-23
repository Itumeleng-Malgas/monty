#include "monty.h"

/**
 * _push - add node to the list
 * @head: head pointer
 * @counter: line_number
*/
void _push(stack_t **head, unsigned int counter)
{
	if (app_data.type == STACK)
		add_at_head(head, counter);
	else
		add_at_tail(head, counter);
}
