#include "monty.h"
app_data_t app_data = {STACK, NULL, NULL, NULL};

/**
* main - prog entry pointer
* @argc: arguments count
* @argv: arguments vector
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	size_t size = 0;
	unsigned int counter = 0;
	stack_t *stack = NULL;
	long char_count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	app_data.file = fopen(argv[1], "r");
	if (!app_data.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		char_count = getline(&app_data.line, &size, app_data.file);
		if (char_count > 0)
		{
			counter++;
			execute(&stack, counter);
		}
		else
			break;
	}

	free_stack(stack);
	free(app_data.line);
	fclose(app_data.file);
	return (0);
}
