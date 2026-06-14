#include "monty.h"

/**
 * pstr - prints stack as string
 * @stack: stack head
 * @line_number: line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;

	while (tmp)
	{
		if (tmp->n <= 0 || tmp->n > 127)
			break;

		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");
}
