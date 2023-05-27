#include "monty.h"
/**
 * free_stack - free stack
 *
 * @stack: stack to be freed
 *
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;
	stack_t *head;

	head = *stack;
	while (head != NULL)
	{
		temp = head;
		free(temp);
		head = head->next;
	}
}

