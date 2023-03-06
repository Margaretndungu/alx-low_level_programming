#include "main.h"
/**
 * _memset - function that fills memory with a constant byte
 * @n:input
 * @s:pointer
 * @b:constant byte
 * Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
