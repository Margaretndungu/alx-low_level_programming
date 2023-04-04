#include "lists.h"
/**
 * delete_nodeint_at_index - function that deletes the node at index
 * @head:pointer to the node
 * @index:index to the node
 * Return: 1(success), or -1(fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tmp = *head;
	listint_t *current = NULL;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(tmp);
		return (1);
	}
	while (i < index - 1)
	{
		if (!tmp || !(tmp->next))
			return (-1);
		tmp = tmp->next;
		i++;
	}
	current = tmp->next;
	tmp->next = current->next;
	free(current);

	return (1);
}

