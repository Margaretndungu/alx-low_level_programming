#include"main.h"
/**
 * get_endianesss - function that checks the endianness.
 * Return:0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int value = 1;
	unsigned char *ptr = (unsigned char *)&value;

	return ((*ptr == 1) ? 1 : 0);
}
