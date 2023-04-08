#include <stdbool.h>
#include <stddef.h>
#include "main.h"

/**
 * binary_to_uint - function that converts a binary number
 * @b:pointer
 * Return:converted number or 0 if
 * there is one or more chars in the string b
 * that is not 0 or 1 b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
	{
		return (0);
	}

	while (*b != '\0')
	{
		if (*b == '0')
		{
			result = result << 1;
		}
		else if (*b == '1')
		{
			result = (result << 1) | 0x1;
		}
		else
		{
			return (0);
		}
		b++;
	}
	return (result);
}
