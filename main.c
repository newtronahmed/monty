#include "monty.h"
/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: array of strings of arguments
 *
 * Return: always 0
 */
int token = 1;

int main(int argc, char **argv)
{
    char *line = NULL;
    char *filename, *op_code, *num_str;
    int i;
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
        i = 0;
        line_num++;

        if (read_bytes <= 1 || line[0] == '\n')
            continue;

        op_code = strtok(line, " \n");
        
        if (op_code == NULL)
            continue;
        if (strcmp(op_code, "push") == 0)
        {
            num_str = strtok(NULL, " \n");

            if (num_str == NULL)
            {
                fprintf(stderr, "L%d: usage: push integer\n",
                        line_num);
                free(line);
                free_stack(&stack);
                fclose(file);
                exit(EXIT_FAILURE);
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
                    free(line);
                    free_stack(&stack);
                    fclose(file);
                    exit(EXIT_FAILURE);
                }
            }

            token = atoi(num_str);
        }
        op_func(&stack, op_code,  line_num);
    }
    free(line);
    fclose(file);
    free_stack(&stack);
    return (0);
}
