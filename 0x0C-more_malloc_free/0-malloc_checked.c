#include"main.h"
#include <stdlib.h>
/**
 * malloc_checked - function that allocates memory using malloc
 * @b:size_t
 * Return: pointer to allocated memory,else status value of 98
 */
void *malloc_checked(unsigned int b)
{
int *ptr;

ptr = malloc(b);
return (ptr);
if (ptr == NULL)
exit(98);
}
