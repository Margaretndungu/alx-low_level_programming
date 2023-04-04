#include "lists.h"
/**
 * get_nodeint_at_index -  function that returns the
 * nth node of a listint_t linked list.
 * @head:pointer to the node
 * @index:index of the node, starting at 0
 * Return: pointer to nth node or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current = head;
	unsigned int  count = 0;

	while (current != NULL)
	{
		if (count == index)
			return (current);
		count++;
		current = current->next;
	}
	return (NULL);
}
