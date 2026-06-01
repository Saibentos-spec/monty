#include "monty.h"

/**
 * sub - subtracts top element from second top element
 * @stack: pointer to stack
 * @line_number: line number of opcode
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	second->n = second->n - first->n;

	*stack = second;
	second->prev = NULL;

	free(first);
}
