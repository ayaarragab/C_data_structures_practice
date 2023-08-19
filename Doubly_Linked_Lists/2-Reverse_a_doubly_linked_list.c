#include "lists.h"
/**
 * Reverse_a_doubly_linked_list - reverses a doubly linked list
 * @head: head
 * Return: reversed linkedlist
*/
dlistint_t *Reverse_a_doubly_linked_list(dlistint_t **head)
{
	dlistint_t *temp = *head, *current, *temp_prev;

	while (temp->next != NULL)
		temp = temp->next;
	(*head) = temp;
	current = (*head);
	while (current)
	{
		temp_prev = current->prev;
		current->prev = current->next;
		current->next = temp_prev;
		current = current->next;
	}
	return (*head);
}
