#include "main.h"
/**
 * get_bit - function that returns the value of a bit at a given index.
 * @n:unsigned long int
 * @index: unsigned index
 * Return:value of the bit at index or -1 if an error occurs
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask = 1UL << index;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	if (n & mask)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
