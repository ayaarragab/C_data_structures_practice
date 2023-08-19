#include "lists.h"
/**
 * calc_len_list - calculates length of a list
 * @head: head
 * Return: length
*/
unsigned int calc_len_list(dlistint_t *head)
{
	dlistint_t *temp = head;
	unsigned int count = 0;

	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
/**
 * find_mid - finds the middle value of a linked list
 * @head: head
 * Return: middle value or -1
*/
int find_mid(dlistint_t **head)
{
	dlistint_t *temp = *head;
	int number_of_nodes = calc_len_list(*head), i = 0;

	if (head == NULL || *head == NULL)
		return (-1);
	if (number_of_nodes % 2 == 0)
	{
		while (i < number_of_nodes / 2)
		{
			temp = temp->next;
			i++;
		}
		return (temp->n);
	}
	while (i < number_of_nodes / 2)
	{
		temp = temp->next;
		i++;
	}
	return (temp->n);
}
