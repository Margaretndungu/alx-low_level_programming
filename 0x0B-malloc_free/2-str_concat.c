#include "main.h"
#include <stdlib.h>
/**
 * str_concat - function that concatenates two strings
 * @s1:string 1
 * @s2:string 2
 * Return: NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *k;
	int i, j, r, l;

	if (s1 == 0)
		s1 = " ";
	if (s2 == 0)
		s2 = " ";
	for (i = 0; s1[i] != '\0'; i++)
		;
	for (j = 0; s2[j] != '\0'; j++)
		;
	j++;
	k = malloc(i * sizeof(*s1) + j * sizeof(*s2));
	if (k == 0)
		return (NULL);
	for (r = 0, l = 0; r < i + j; r++)
	{
		if (r < i)
			k[r] = s1[r];
		else
			k[r] = s2[l++];
	}
	return (k);
}
