#include "lists.h"
/**
 * pint - implementation of monty pint
 * @data: will not be used
 * Return: nothing
*/
void pint(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    if (current == NULL)
    {
       fprintf(stderr, "L%d: can't pint, stack empty", line_number);
       exit(EXIT_FAILURE);
    }
    printf("%d\n", current->n);
}
