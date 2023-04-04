#include "lists.h"
/**
 * insert_nodeint_at_index -  function that inserts
 * a new node at a given position.
 * @head:pointer to the node
 * @idx:index to the new node
 * @n:integer
 * Return:address of the new node else NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *newnode;
	listint_t *tmp = *head;
	unsigned int i;

	newnode = malloc(sizeof(listint_t));
	if (!newnode || !head)
		return (NULL);
	newnode->n = n;
	newnode->next = NULL;

	if (idx == 0)
	{
		newnode->next = *head;
		*head = newnode;
		return (newnode);
	}
	for (i = 0; tmp && i < idx; i++)
	{
	if (i == idx - 1)
		{
	newnode->next = tmp->next;
	tmp->next = newnode;
	return (newnode);
	}
	else
	tmp = tmp->next;
	}
	return (NULL);
}
