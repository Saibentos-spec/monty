#include "monty.h"

/**
 * mod - computes remainder of second top divided by top element
 * @stack: pointer to stack
 * @line_number: line number of opcode
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	if (first->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	second->n = second->n % first->n;

	*stack = second;
	second->prev = NULL;

	free(first);
}
