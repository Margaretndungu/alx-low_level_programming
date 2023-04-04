#include <stdlib.h>
#include "lists.h"
/**
 * free_listint - function that frees a listint_t list.
 * @head:pointer to the nodes
 * Return: Always 0 (success)
 */
void free_listint(listint_t *head)
{
	listint_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
