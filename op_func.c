#include "monty.h"
/**
 * op_func - operations
 *
 * @stack: stack
 * @op_code: code
 * @line_num: line number
 *
 * Return: corresponding func or exit
 */

stack_t *op_func(stack_t **stack, char *op_code, unsigned int line_num)
{
	int i = 0;

	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"nop", nop},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};

	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, op_code) == 0)
		{
			return ((ops[i]).f(stack, line_num));
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op_code);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
