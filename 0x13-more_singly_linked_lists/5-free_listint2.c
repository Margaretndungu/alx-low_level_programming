#include <stdlib.h>
#include "lists.h"
/**
 * free_listint2 -  function that frees a listint_t list.
 * @head:pointer to the node
 * Return: Always 0 (success)
 */
void free_listint2(listint_t **head)
{
	listint_t *tmp;

	if (head == NULL)
		return;
	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
	*head = NULL;
}
