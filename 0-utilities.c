#include "monty.h"

/**
* free_stack - frees a list
* @head: head pointer
*/
void free_stack(stack_t *head)
{
	stack_t *current = head;

	while (head)
	{
		current = head->next;
		free(head);
		head = current;
	}
}

/**
* add_at_head - adds node at the beginning of the list
* @head: head pointer
* @data: new data
*/
void add_at_head(stack_t **head, const int data)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = data;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}

/**
* add_at_tail - add note at the end of the list
* @head: head pointer
* @data: new data
*/
void add_at_tail(stack_t **head, const int data)
{
	stack_t *h, *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = data;
	new_node->next = NULL;
	h = *head;

	if (h != NULL)
	{
		while (h->next != NULL)
			h = h->next;
		h->next = new_node;
	}
	else
	{
		*head = new_node;
	}
	new_node->prev = *head;
}
