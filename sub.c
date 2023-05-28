#include "monty.h"

/**
 * sub - subtract top 2 elements
 * @stack: - stack
 * @line_num: - line number
 *
 * Return: stack
 */
stack_t *sub(stack_t **stack, unsigned int line_num)
{
	stack_t *head;
	int sub = 0;

	head = *stack;
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	sub = (head->next->n) - (head->n);
	*stack = (*stack)->next;
	free(head);

	if (*stack != NULL)
		(*stack)->prev = NULL;
	(*stack)->n = sub;
	return (*stack);
}
