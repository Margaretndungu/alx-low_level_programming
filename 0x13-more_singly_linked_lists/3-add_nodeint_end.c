#include "lists.h"
/**
 *add_nodeint_end - function that adds a new
 *node at the end of a listint_t list
 *@head:pointer to the node address
 *@n: integer
 *Return:address of the new element,
 *NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newnode = NULL;
	listint_t *current = *head;

	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = n;
	newnode->next = NULL;

	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = newnode;
	}
	return (newnode);
}
