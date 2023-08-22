#include "lists.h"
/**
 * check_malloc - prints to stderr and exit by EXIT_FAILURE if malloc failed
 * @space: space that doesn't allocated
 * Return: nothing
*/
void check_malloc(stack_t *stack)
{
    if (stack == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    return;
}
