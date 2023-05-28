#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 *
 * @stack: - stack
 * @line_num: - line number
 *
 * Return: void
 */
stack_t *pint(stack_t **stack, unsigned int line_num)
{
	stack_t *head = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	head = *stack;
	printf("%d\n", head->n);
	return (head);
}
