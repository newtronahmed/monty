#include "monty.h"

/**
 * mod - mod top 2 elements
 * @stack: - stack
 * @line_num: - line number
 *
 * Return: stack
 */
stack_t *mod(stack_t **stack, unsigned int line_num)
{
	stack_t *head;
	int mod = 0;

	head = *stack;
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	mod = (head->next->n) % (head->n);
	*stack = (*stack)->next;
	free(head);

	if (*stack != NULL)
		(*stack)->prev = NULL;
	(*stack)->n = mod;
	return (*stack);
}
