#include<stdarg.h>
/**
 * sum_them_all - sum of all its parameters
 * @n:number of arguments
 * Return: 0  if n == 0 else sum
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	int sum = 0;
	unsigned int i;

	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		sum += va_arg(args, int);
	}
	va_end(args);
	return (sum);
}
