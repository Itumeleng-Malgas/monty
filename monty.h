#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO Holberton project
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO Holberton project
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* enum data_struct_type - defines supported data structures
* @STACK: stack type
* @QUEUE: queue type
*/
enum data_struct_type
{
	STACK,
	QUEUE
};

/**
* struct app_data_s - holds application
* @type: data structure type
* @file: monty file handle
* @line: file data per line
* @arg: arguments
*/
typedef struct app_data_s
{
	enum data_struct_type type;
	FILE *file;
	char *line;
	char *arg;
} app_data_t;
extern app_data_t app_data;

int execute(stack_t **head, unsigned int counter);

void _push(stack_t **head, unsigned int n);
void _pall(stack_t **head, unsigned int n);
void _pint(stack_t **head, unsigned int n);

/** 0-utilities **/
void free_stack(stack_t *head);
void add_at_head(stack_t **head, const int data);
void add_at_tail(stack_t **head, const int data);

#endif
