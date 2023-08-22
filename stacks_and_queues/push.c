#include "lists.h"
/**
 * push - implementation of monty push
 * @stack: pointer to top of the stack
 * @line_number: line_number
 * Return: nothing
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *pushed_node;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	pushed_node = malloc(sizeof(stack_t));
	check_malloc(pushed_node);
	pushed_node->n = 0;
	pushed_node->next = *stack;
	*stack = pushed_node;
}
