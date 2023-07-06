#include "main.h"
/**
 * binary_to_uint - function that converts a binary number to an unsigned int
 * @b:pointer to the string
 * Return:0 or 1
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int  i;

	if (b == NULL)
	{
		return (0);
	}

	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] == '0')
		{
			result = result * 2;
		}
		else if (b[i] == '1')
		{
			result = result * 2 + 1;
		}
		else
		{
			return (0);
		}
	}
	return (result);
}
