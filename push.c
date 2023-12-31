#include "monty.h"

/**
 * _push - add node to the list
 * @head: head pointer
 * @counter: line_number
*/
void _push(stack_t **head, unsigned int counter)
{
	int is_digit = 0, i = 0;

	if (app_data.arg)
	{
		while (app_data.arg[i] != '\0')
		{
			/* check if the character is not a digit (0-9) */
			if (app_data.arg[i] > 57 || app_data.arg[i] < 48)
				is_digit = 1;
			if (is_digit)
			{
				fprintf(stderr, "L%d: usage: push integer\n", counter);
				clean_up(head);
			}
			i++;
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		clean_up(head);
	}

	if (app_data.type == STACK)
		add_at_head(head, atoi(app_data.arg));
	else
		add_at_tail(head, atoi(app_data.arg));
}
