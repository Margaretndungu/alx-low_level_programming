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
        int i;

        for (i = 0; i < argc; i++)
        {
                printf("%d", argc);
        }
        printf("\n");
        return (0);
}
