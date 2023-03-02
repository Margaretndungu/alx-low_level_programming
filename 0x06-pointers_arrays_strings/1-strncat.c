#include "main.h"
/**
 * _strncat -function that concatenates two strings
 * @src:char type string
 * @dest:char type string
 * @n:size of string
 * Description: -strncat to concatenate two strings
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int a;
	int b;

	a = 0;
	while (dest[a] != '\0')
	{
		a++;
	}
	b = 0;
	while (b < n && src[b] != '\0')
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	dest[a] = '\0';
	return (dest);
}
