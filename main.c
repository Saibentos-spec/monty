#include "monty.h"

/**
 * main - Monty interpreter entry point
 * @ac: argument count
 * @av: argument vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int main(int ac, char **av)
{
    FILE *file;
    char line[256];
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    if (ac != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(av[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", av[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file))
    {
        char *opcode = strtok(line, " \n\t");
        char *arg = strtok(NULL, " \n\t");
        line_number++;

        if (!opcode || opcode[0] == '#')
            continue;

        get_op_func(opcode, &stack, line_number, arg);
    }

    free_stack(stack);
    fclose(file);
    return 0;
}
