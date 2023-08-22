#include "lists.h"
/**
 * pop - implementation of monty pop
 * @stack: pointer to top of the stack
 * @line_number: line_number
 * Return: nothing
*/
void pop(stack_t **stack, unsigned int line_number)
{
	int num = (*stack)->n;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	printf("%d\n", num);
}
