#include "monty.h"

/**
* free_stack - frees a list
* @head: head pointer
*/
void free_stack(stack_t *head)
{
	stack_t *current;

	current = head;
	while (head)
	{
		current = head->next;
		free(head);
		head = current;
	}
}

/**
 * addnode - add node at the beginning of list
 * @head: head pointer
 * @n: new_value
*/
void addnode(stack_t **head, int n)
{

	stack_t *current, *new_node = malloc(sizeof(stack_t));
	current = *head;

	if (new_node == NULL)
	{
        printf("Error: Out of memory\r\n");
		exit(0); 
    }
	if (current)
		current->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
