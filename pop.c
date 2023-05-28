#include "monty.h"
/**
 * pop - remove the top element of stack
 *
 * @stack: - stack
 * @line_num: - line number
 *
 * Return: stack
 */
stack_t *pop(stack_t **stack, unsigned int line_num)
{
	stack_t *head;

	head = *stack;
	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(head);
	return (*stack);
}
