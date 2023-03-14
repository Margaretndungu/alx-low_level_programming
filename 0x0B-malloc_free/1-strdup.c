#include "main.h"
#include <stdlib.h>
/**
 * _strdup - function that returns a pointer
 * to a newly allocated space in memory
 * @str:string
 * Return: NULL if insufficient memory was available
 */
char *_strdup(char *str)
{
	char *c;
	unsigned int k = 0;
	unsigned int s = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[k])
		k++;
	c = malloc(sizeof(char) * (k + 1));
	if (c == NULL)
		return (NULL);
	while (str[s])
	{
		c[s] = str[s];
		s++;
	}
	c[s + 1] = 0;
	return (c);
}
