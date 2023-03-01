#include "main.h"
/**
 * _strcat - function to append src string to dest string
 * @src: char type string
 * @dest: char type string
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int i, len = 0;

	for (i = 0; dest[i] != '\0'; i++)
	{
		len++;
	}
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[len + i] = src[i];
	}
	dest[len + i] = '\0';
	return (dest);
}
