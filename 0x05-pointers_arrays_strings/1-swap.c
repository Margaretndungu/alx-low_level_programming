#include "main.h"
/**
 * swap_int - function to swap values of two integers
 * @a:integer value
 * @b:integer value
 * Return: Always 0
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
