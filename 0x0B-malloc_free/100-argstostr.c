#include "main.h"
#include <stdlib.h>
/**
 * argstostr - function that concatenates
 * all the arguments of your program
 * @ac: int input
 * @av:double pointer array
 * Return: pointer to a new string
 */
char *argstostr(int ac, char **av)
{
	int a, n, j = 0, len = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (a = 0; a < ac; a++)
	{
		for (n = 0; av[a][n]; n++)
			len++;
	}
	len += ac;

	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);

	for (a = 0; a < ac; a++)
	{
		for (n = 0; av[a][n]; n++)
		{
			str[j] = av[a][n];
			j++;
		}
		if (str[j] == '\0')
		{
			str[j++] = '\n';
		}
	}
	return (str);
}
