#include "monty.h"

/**
 * rotl - rotates stack left
 * @stack: stack head
 * @line_number: line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *last;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	top = *stack;
	last = *stack;

	while (last->next)
		last = last->next;

	*stack = top->next;
	(*stack)->prev = NULL;

	last->next = top;
	top->prev = last;
	top->next = NULL;
}
