void push(stack_t **stack, unsigned int line_number, char *arg)
{
    stack_t *new_node;
    int value;

    if (!arg || is_number(arg) == 0)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(arg);

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
        exit(EXIT_FAILURE);

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}
