#include "monty.h"
/**
  *_rotl- rotates the stack
  *@head: head pointer
  *@counter: line_number
 */
void _rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *current;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	current = (*head)->next;
	current->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = current;
}
