#include "monty.h"

/**
* execute - run the commands
* @head: list head pointer
* @counter: line counter
*/
void execute(stack_t **head, unsigned int counter)
{
	unsigned int i = 0;
	char *opcode;

	instruction_t op_instr[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint}, {"pop", _pop},
		{"swap", _swap}, {"add", _add}, {"nop", _nop}, {"sub", _sub},
		{NULL, NULL}
	};

	opcode = strtok(app_data.line, " \n\t");
	if (opcode && opcode[0] == '#')
		return;

	app_data.arg = strtok(NULL, " \n\t");
	while (op_instr[i].opcode && opcode)
	{
		if (strcmp(opcode, op_instr[i].opcode) == 0)
		{
			op_instr[i].f(head, counter);
			return;
		}
		i++;
	}

	if (opcode && op_instr[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
		clean_up(head);
	}
}
