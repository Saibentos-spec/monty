#include "monty.h"

/**
 * main - Monty bytecode interpreter
 * @ac: argument count
 * @av: argument vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
char *ptr = line;

while (*ptr == ' ' || *ptr == '\t')
	ptr++;

if (*ptr == '#')
	continue;

int main(int ac, char **av)
{
	FILE *file;
	char line[256];
	char *opcode, *arg;
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
		line_number++;

		opcode = strtok(line, " \t\n");
		arg = strtok(NULL, " \t\n");

		if (!opcode || opcode[0] == '#')
			continue;

		get_op_func(opcode, &stack, line_number, arg);
	}

	free_stack(stack);
	fclose(file);

	return (EXIT_SUCCESS);
}
