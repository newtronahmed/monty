#include "monty.h"

/**
 * _div - div top 2 elements
 * @stack: - stack
 * @line_num: - line number
 *
 * Return: stack
 */
stack_t *_div(stack_t **stack, unsigned int line_num)
{
	stack_t *head;
	int div = 0;

	head = *stack;
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	div = (head->next->n) / (head->n);
	*stack = (*stack)->next;
	free(head);

	if (*stack != NULL)
		(*stack)->prev = NULL;
	(*stack)->n = div;
	return (*stack);
}
