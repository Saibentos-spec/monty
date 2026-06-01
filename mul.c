#include "monty.h"

void mul(stack_t **stack, unsigned int line_number)
{
    stack_t *first, *second;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    first = *stack;
    second = first->next;

    second->n *= first->n;
    second->prev = NULL;

    *stack = second;
    free(first);
}
