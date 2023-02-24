#include "main.h"
/**
 * print_numbers - Print the number since 0 upto 9
 * Return: The numbers since 0 upto 9
 */
void print_numbers(void)
{
	int c;

	for (c = 0; c <= 9; c++)
	{
		_putchar(c + '0');
	}
	_putchar('\n');
}
