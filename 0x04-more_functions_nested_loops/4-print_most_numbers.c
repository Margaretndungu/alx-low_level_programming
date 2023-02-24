#include "main.h"
/**
 * print_most_number - Print numbers 0 to 9 except 2 and 4
 * Return: The numbers from 0 to 9 except 2 to 4
 */
void print_most_numbers(void)
{
	int x;

	for (x = 0; x <= 9; x++)
	{
		if (x == 2 || x ==4)
		continue;
		_putchar(x);
	}
	_putchar('\n');
}
