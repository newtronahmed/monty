#include "monty.h"
/**
 * push - push to stack
 *
 * @stack: stack
 * @line_num: line number
 *
 * Return: newnode
 */
stack_t *push(stack_t **stack, unsigned int line_num __attribute__((unused)))
{
	stack_t *new_node;

	/* Create new node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	/* Initialize the new node with the value of token */
	new_node->n = token;
	/* New node is placed at the beginning of the list */
	new_node->prev = NULL;
	new_node->next = *stack;

	/* If new node is not alone, update the following one */
	if (*stack != NULL)
		(*stack)->prev = new_node;

	/* head points to the new node */
	*stack = new_node;

	return (new_node);
}
