#include "main.h"
/**
 * get_endianness - function that checks the endianness.
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int x = 1;
	char *p = (char *) &x;

	return ((*p == 1) ? 1 : 0);
}
