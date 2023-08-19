#include "lists.h"
/**
 * main - check the code
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head;

    head = NULL;
    add_dnodeint(&head, 0);
    add_dnodeint(&head, 1);
    add_dnodeint(&head, 2);
    add_dnodeint(&head, 3);
    add_dnodeint(&head, 4);
    add_dnodeint(&head, 98);
    add_dnodeint(&head, 402);
    add_dnodeint(&head, 1024);
    add_dnodeint(&head, 5000);
    print_dlistint(head);
    printf("After reversing:\n");
    Reverse_a_doubly_linked_list(&head);
    print_dlistint(head);
    free_dlistint(head);
    return (EXIT_SUCCESS);
}
