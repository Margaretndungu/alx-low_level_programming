#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - function that returns a pointer
 * to a 2 dimensional array of integers.
 * @width:dimension
 * @height:dimension
 * Return: NULL on failure
 */
int **alloc_grid(int width, int height)
{
	int **see;
	int i, s;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}
	see = malloc(sizeof(int) * height);
	if (see == NULL)
	{
		free(see);
		return (NULL);
	}
	for (i = 0; i < height; i++)
	{
		see[i] = malloc(sizeof(int) * width);
		if (see == NULL)
		{
			free(see);
			return (NULL);
		}
		for (s = 0; s < width; s++)
		{
			see[i][s] = 0;
		}
	}
	return (see);
}
