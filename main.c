#include "monty.h"
int token = 1;
void handle_exit(char *line, stack_t **stack, FILE *file);
int handle_push(char *num_str, unsigned int line_num);

/**
 * handle_exit - handle exit of functions
 * @line: current line to free
 * @stack: stack to free
 * @file: file to close
 *
 * Return: void
 */
void handle_exit(char *line, stack_t **stack, FILE *file)
{
		free(line);
		free_stack(stack);
		fclose(file);
}
/**
 * handle_push - handle push command
 * @num_str: num string
 * @line_num: line number
 * Return: int
 */
int handle_push(char *num_str, unsigned int line_num)
{
	int i = 0;

	if (num_str == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n",
				line_num);
		return (1);
	}

	if (num_str[0] == '-' && num_str[1] != '\0')
		i = 1;

	for (; num_str[i] != '\0'; i++)
	{
		if (isdigit(num_str[i]) == 0)
		{
			fprintf(stderr,
					"L%d: usage: push integer\n",
					line_num);
			return (1);
		}
	}
	return (0);
}
/**
 * main - Entry point
 * @argc: number of args
 * @argv: array of args strings
 * Return: always 0
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	char *filename, *op_code, *num_str;
	size_t nread = 0;
	ssize_t read_bytes = 0;
	unsigned int line_num = 0;
	FILE *file;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((read_bytes = getline(&line, &nread, file)) != EOF)
	{
		line_num++;
		if (read_bytes <= 1 || line[0] == '\n' || line[0] == '#')
			continue;
		op_code = strtok(line, " \n");
		if (op_code == NULL)
			continue;
		if (strcmp(op_code, "push") == 0)
		{
			num_str = strtok(NULL, " \n");
			if (handle_push(num_str, line_num))
			{
				handle_exit(line, &stack, file);
				exit(EXIT_FAILURE);
			}
			token = atoi(num_str);
		}
		op_func(&stack, op_code,  line_num);
	}
	handle_exit(line, &stack, file);
	return (0);
}
