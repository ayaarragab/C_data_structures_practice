#include "lists.h"
/**
 * error_instruction - when an unknown instruction
 * @stack: stack
 * Return: nothing
*/
void error_instruction(stack_t *stack, int line_number, char *instr, char **buf)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instr);
	free_2d(buf);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
/**
 * errno_argc - argc error
 * @stack: stack
 * Return: nothing
*/
void errno_argc(stack_t *stack)
{
	fprintf(stderr, "USAGE: monty file\n");
	free_stack(stack);
	exit(EXIT_FAILURE);
}
/**
 * errno_fd - fd error
 * @str: filename
 * @stack: stack
 * Return: nothing
*/
void errno_fd(char *str, stack_t *stack)
{
	fprintf(stderr, "Error: Can't open file %s\n",str);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
instruction_t array_of_instructions[6] = {
	{"pop", pop},
	{"pint", pint},
	{"pall", pall},
	{"push", push},
	{"swap", swap},
	{"nop", nop}
};
/**
 * make_array_of_strings - func
 * @command: command entered
 * Return: array of strings
 */
char **make_array_of_strings(char *command)
{
	char *token;
	char **tokens = malloc(BUFSIZ * sizeof(char *));
	int num_tokns = 0, i;

	token = strtok(command, " ");

	if (tokens == NULL || token == NULL)
		return (NULL);

	while (token != NULL)
	{
		tokens[num_tokns] = malloc(sizeof(token));
		if (tokens[num_tokns] == NULL)
			return (NULL);
		strcpy(tokens[num_tokns], token);
		if (tokens[num_tokns] == NULL)
		{
			for (i = 0; i < num_tokns; i++)
				free(tokens[i]);
			free(tokens);
			return (NULL);
		}
		num_tokns++;
		token = strtok(NULL, " ");
	}

	tokens[num_tokns] = NULL;
	return (tokens);
}
/**
 * main - main function
 * @argv: arguments vector array
 * @argc: argv length
 * Return: 0 or other thing in faliure
*/
int main(int argc, char **argv)
{
	stack_t *stack = malloc(sizeof(stack_t));
	int i = 0;
	size_t n = 0;
	ssize_t n_characters;
	char *buffer = NULL, **splitted_line, *filename;
	FILE *monty_file;

	check_malloc(stack);
	stack = NULL;
	if (argc != 2)
		errno_argc(stack);
	check_malloc2(buffer);
	monty_file = fopen(argv[1], "r");
	if (monty_file == NULL)
		errno_fd(argv[1], stack);
	while ((n_characters = getline(&buffer, &n, monty_file)) != -1)
	{
		splitted_line = make_array_of_strings(buffer);
		if (i == 5)
			error_instruction(stack, __LINE__, splitted_line[0], splitted_line);
		while (i < 6)
		{
			if (strcmp(splitted_line[0], array_of_instructions[i].opcode) == 0)
			{
				array_of_instructions[i].f(&stack, __LINE__);
				if (strcmp(splitted_line[0], "push") == 0)
				{
					stack->n = atoi(splitted_line[1]);
					break;
				}
				break;
			}
			i++;
		}
	}
	fclose(monty_file);
	free_2d(splitted_line);
	free(buffer);
	free_stack(stack);
	return (0);
}
