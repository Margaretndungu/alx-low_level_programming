#include "main.h"
#include <string.h>
/**
 * binary_to_uint -  function that converts a binary
 * number to an unsigned int
 * @b:ponter to the string
 * Return: converted number,
 * 0 if there is one or more chars in the string b that is not 0 or
 * 1 b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	size_t len;
	unsigned int result = 0;
	size_t i;

	if (b == NULL)
	{
		return (0);
	}

	len = strlen(b);

	for (i = 0; i < len; i++)
	{
		if (b[i] == '0')
		{
			result = (result << 1) | 0;
		}
		else if (b[i] == '1')
		{
			result = (result << 1) | 1;
		}
		else
		{
			free((void *)b);
			exit(1);
		}
	}
		free((void *)b);
		return (result);
}
