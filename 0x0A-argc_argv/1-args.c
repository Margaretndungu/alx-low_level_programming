#include <stdio.h>
#include "main.h"
/**
 * main - Entry point
 * @argc:argument count
 * @argv:argument vector
 * Return: Always 0 (success)
 */
int main(int argc, char *argv[])
{
(void) argv;/*ignore argv*/

printf("%d", argc - 1);
printf("\n");
return (0);
}
