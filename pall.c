#include "monty.h"

/**
 * pall - print all
 * @stack: ponter to the list stack
 * @line_number: unused variable
 * Return: the address of the first node
 */
stack_t *pall(stack_t **stack,
	      unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp;
	size_t node_c = 0;

	tmp = *stack;

	if (*stack == NULL)
	{
		return (NULL);
	}

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
		node_c++;
	}

	return (*stack);
}
