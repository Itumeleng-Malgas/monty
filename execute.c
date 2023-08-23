#include "monty.h"

/**
* execute - run the commands
* @head: list head pointer
* @counter: line counter
* Return: 1 success 0 failure
*/
int execute(stack_t **head, unsigned int counter)
{
	unsigned int i = 0;
	char *opcode;

	instruction_t op_instr[] = {
		{"push", _push},
		{"pall$", _pall},
		{NULL, NULL}
	};

	opcode = strtok(app_data.line, " \n\t");
	app_data.arg = strtok(NULL, " \n\t");
	while (op_instr[i].opcode && opcode)
	{
		if (strcmp(opcode, op_instr[i].opcode) == 0)
		{
			op_instr[i].f(head, counter);
			return (0);
		}
		i++;
	}

	if (opcode && op_instr[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
		fclose(app_data.file);
		free_stack(*head);
		free(app_data.line);
		exit(EXIT_FAILURE);
	}
	return (1);
}
