#include "main.h"
/**
 * clear_bit -  function that sets the value of a bit to 0 at a given index.
 * @n:unsigned long int pointer
 * @index:unsigned int
 * Return:1 if it works else -1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = ~(1UL << index);

	if (index >= sizeof(unsigned long int) * 8 || n == NULL)
	{
		return (-1);
	}

	*n &= mask;

	return (1);
}
