#include "main.h"
#include <stdio.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - gives allocation 1024 bytes for a buffer
 * @file:file buffer
 * Return:pointer to the new buffer
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: can't wrire to %s\n", file);
		exit(99);
	}
	return (buffer);
}
/**
 * close_file - closes file descriptor
 * @fd:file descriptor
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: cant't close fd%d\n", fd);
		exit(100);
	}
}
/**
 * main - copy contents to another file
 * @argc: number of argument
 * @argv: argument vector
 *
 * Return: Always 0 (success)
 * if you can not read it, exit with code 98
 * if write to file_to fails, exit with code 99
 * if you can not close a file descriptor , exit with code 100 and print Error:
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;

	char *buffer;


		if (argc != 3)
		{
			dprintf(STDERR_FILENO, "Usage:cp file_from file_to\n");
			exit(97);
		}
	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO, "Error:can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}
		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO, "Error:can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);
	} while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);
	return (0);
}
