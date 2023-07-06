#include "main.h"
/**
 * flip_bits -  function that returns the number of bits you would
 * need to flip to get from one number to another.
 * @n:unsigned long int
 * @m:unsigned long int
 * Return: number of bits you would need to flip to get
 * from one number to another.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flipped = n ^ m;
	unsigned int count = 0;

	while (flipped != 0)
	{
		count++;
		flipped &= (flipped - 1);
	}
	return (count);
}
