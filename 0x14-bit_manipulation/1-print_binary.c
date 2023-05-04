#include "main.h"
/**
 * print_binary - function that prints the binary representation of a number
 * @n:input value
 * Return: Nothing
 */
void print_binary(unsigned long int n)
{
	int bit_count = sizeof(unsigned long int) * CHAR_BIT;
	unsigned long int mask = (1UL << (bit_count - 1));
	int i;

	for (i = 0; i < bit_count; i++)
	{
		if ((n & mask) != 0)
		{
			putchar('1');
		}
		else
		{
			putchar('0');
		}
		mask >>= 1;
	}
	putchar('\n');
}
