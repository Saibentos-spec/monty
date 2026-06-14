if (mode == STACK_MODE)
{
	new->next = *stack;
	new->prev = NULL;

	if (*stack)
		(*stack)->prev = new;

	*stack = new;
}
else
{
	stack_t *tmp;

	new->next = NULL;

	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
		return;
	}

	tmp = *stack;

	while (tmp->next)
		tmp = tmp->next;

	tmp->next = new;
	new->prev = tmp;
}
