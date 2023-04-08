#include"main.h"
#include<stdio.h>
/**
 * print_binary - function that prints the binary
 * representation of a number.
 * @n:integer
 * Return: binary representation of a number.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);

	int num_bits = sizeof(unsigned long int) * 8;

	int i;

	for (i = 0; i < num_bits; i++)
	{
		if (n & mask)
		{
			putchar('1');
		}
		else
		{
			putchar('0');
		}
		mask >>= 1;
	}
	fflush(stdout);
}
