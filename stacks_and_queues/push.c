#include "lists.h"
/**
 * push - implementation of monty push
 * @data: data to be pushed
 * Return: nothing
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *pushed_node;

	pushed_node = malloc(sizeof(stack_t));
	check_malloc(pushed_node);
	pushed_node->n = line_number;
	pushed_node->next = *stack;
	*stack = pushed_node;
}
