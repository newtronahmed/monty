#include "monty.h"

/**
 * add - adds top 2 elements
 * @stack: - stack
 * @line_num: - line number
 *
 * Return: stack
 */
stack_t *add(stack_t **stack, unsigned int line_num)
{
	stack_t *head;
	int sum = 0;

	head = *stack;
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	sum = (head->n) + (head->next->n);
	*stack = (*stack)->next;
	free(head);

	if (*stack != NULL)
		(*stack)->prev = NULL;
	(*stack)->n = sum;
	return (*stack);
}
