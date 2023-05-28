#include "monty.h"

/**
 * mul - subtract top 2 elements
 * @stack: - stack
 * @line_num: - line number
 *
 * Return: stack
 */
stack_t *mul(stack_t **stack, unsigned int line_num)
{
	stack_t *head;
	int mul = 0;

	head = *stack;
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	mul = (head->next->n) * (head->n);
	*stack = (*stack)->next;
	free(head);

	if (*stack != NULL)
		(*stack)->prev = NULL;
	(*stack)->n = mul;
	return (*stack);
}
