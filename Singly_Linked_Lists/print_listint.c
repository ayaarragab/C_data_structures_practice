#include "lists.h"
/**
 * print_listint - prints a singly linked list
 * @h: head
 * Return: size
*/
size_t print_listint(listint_t *h)
{
    listint_t *temp = h;
    size_t count = 0;

    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
        count++;
    }
    return (count);
}
