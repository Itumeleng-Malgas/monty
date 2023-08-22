#include "monty.h"
app_data = {NULL, NULL};

/**
* main - prog entry pointer
* @argc: arguments count
* @argv: arguments vector
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
    size_t char_count = 1, size = 0;
    unsigned int counter = 0;
    stack_t *stack = NULL;
    
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

    while (char_count > 0)
    {
        char_count = getline(&app_data.line, &size, app_data.file);
        if (char_count > 0)
        {
            counter++;
            printf("execute");
        }
    }

    free_stack(stack);
    fclose(app_data.file);
    return (EXIT_SUCCESS);
}
