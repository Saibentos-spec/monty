#include "monty.h"

/**
 * is_number - checks if string is valid integer
 * @s: string to check
 *
 * Return: 1 if valid, 0 otherwise
 */

int is_number(char *s)
{
    if (!s) return 0;
    if (*s == '-' || *s == '+') s++;
    if (!*s) return 0;

    while (*s)
    {
        if (!isdigit(*s))
            return 0;
        s++;
    }
    return 1;
}

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
