#include "monty.h"

void _div(stack_t **stack, unsigned int line_number)
{
    stack_t *first, *second;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    first = *stack;
    second = first->next;

    if (first->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    second->n /= first->n;
    second->prev = NULL;

    *stack = second;
    free(first);
}
