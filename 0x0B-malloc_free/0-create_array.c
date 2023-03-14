#include "main.h"
#include <stdlib.h>
/**
 * create_array - function to create an array of char
 * @size:unsigned int type
 * @c:char type
 * Return:pointer to the array
 */
char *create_array(unsigned int size, char c)
{
	char *k;
	unsigned int s;

	if (size == 0)
	{
		return (NULL);
	}
	k = malloc((size) * sizeof(char));
	if (k == NULL)
	{
		return (NULL);
	}
	s = 0;
	while (s < size)
	{
		k[s] = c;
		s++;
	}
	k[s] = '\0';
	return (k);
}
