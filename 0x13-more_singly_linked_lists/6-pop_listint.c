#include <stdlib.h>
#include "lists.h"
/**
 * pop_listint -  function that deletes the head node of
 * a listint_t linked list , and returns the head node’s data (n).
 * @head:pointer to the node
 * Return: NULL
 */
int pop_listint(listint_t **head)
{
	int data;
	listint_t *tmp;

	if (*head == NULL)
	{
		return (0);
	}
	tmp = *head;
	*head = (*head)->next;
	data = tmp->n;
	free(tmp);

	return (data);
}
