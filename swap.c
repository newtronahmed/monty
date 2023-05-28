#include "monty.h"

/**
 * swap - swap the top 2 elements
 * @stack: stack
 * @line_num:  line number
 *
 * Return: stack
 */
stack_t *swap(stack_t **stack, unsigned int line_num)
{
	stack_t *next;
	int first_num;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	next = (*stack)->next;
	first_num = (*stack)->n;
	(*stack)->n = next->n;
	next->n = first_num;
	return (*stack);
}
