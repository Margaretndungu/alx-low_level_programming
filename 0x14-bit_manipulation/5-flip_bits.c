#include "main.h"
/**
 * flip_bits - function that returns the number of bits
 * @n:first integer
 * @m:second integer
 * Return: number of bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int mask;
	unsigned long int exclusive = n ^ m;

	for (i = 27; i >= 0; i--)
	{
		mask = exclusive >> i;
	if (mask & 1)
		count++;
	}
	return (count);
}
