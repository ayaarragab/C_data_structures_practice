#include "lists.h"
/**
 * pall - implementation of monty pall
 * @data: will not be used
 * Return: nothing
*/
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
