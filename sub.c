#include "monty.h"

/**
  *_sub - subtracts the top element of the stack from the
  * second top element of the stack
  * @head: head pointer
  * @counter: line_number
 */
void _sub(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int dif, n;

	current = *head;
	for (n = 0; current != NULL; n++)
		current = current->next;
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		clean_up(head);
	}
	current = *head;
	dif = current->next->n - current->n;
	current->next->n = dif;
	*head = current->next;
	free(current);
}
