#include "main.h"
/**
 * print_binary - function that prints the binary representation of a number
 * @n:unsigned long integer
 * Return:number
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int leadingzeros = 1;

	if (n == 0)
	{
		putchar('0');
		return;
	}

	while (mask > 0)
	{
		if (n & mask)
		{
			leadingzeros = 0;
			putchar('1');
		}
		else if (!leadingzeros)
		{
			putchar('0');
		}
		mask >>= 1;
	}
}
