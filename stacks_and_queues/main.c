#include "lists.h"
/**
 * main - main function
 * @argv: arguments vector array
 * @argc: argv length
 * Return: 0 or other thing in faliure
*/
int main(int argc, char **argv)
{
	stack_t *stack = malloc(sizeof(stack_t));

	(void)argv;
	(void)argc;
	check_malloc(stack);
	stack = NULL;
	push(&stack, 50);
	push(&stack, 1010);
	push(&stack, 45);
	push(&stack, 300);
	push(&stack, 10000);
	push(&stack, 98);
	push(&stack, 1987);
	push(&stack, 43);
	push(&stack, 23);
	pall(&stack, 0);
	stack->next = NULL;
	pint(&stack, __LINE__);
	free_stack(stack);
	return (0);
}
