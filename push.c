#include "monty.h"

/**
 * push - pushes element to stack
 * @stack: stack pointer
 * @line_number: line number
 * @arg: integer argument
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *new;

	if (!arg || !is_number(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (!new)
		exit(EXIT_FAILURE);

	new->n = atoi(arg);
	new->prev = NULL;
	new->next = *stack;

	if (*stack)
		(*stack)->prev = new;

	*stack = new;
}
