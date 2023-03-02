#include "main.h"
/**
 * _strncat -function that concatenates two strings
 * @src:char type string
 * @dest:char type string
 * @n:size of string
 * Description: -strncat to concatenate two strings
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
if ((dest == NULL) && (src == NULL))
return (NULL);

while (*dest != '\0')
{
dest++;
}
while (n--)
{
while (!(*dest++ = *src++))
{
return (dest);
}
}
*dest = '\0';
return (dest);
}
