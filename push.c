if (mode == STACK_MODE)
{
	/* existing push */
}
else
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		*stack = new;
		return;
	}

	while (tmp->next)
		tmp = tmp->next;

	tmp->next = new;
	new->prev = tmp;
}
