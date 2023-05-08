#include "main.h"
#include <sys/types.h>
/**
 * print_error_exit - number of argument is not the correct
 * one, exit with code 97 and print
 * close_file_exit - close content file
 * main - entry point
 * @fd:file descriptor
 * @argc:argument count
 * @argv:argument vector
 * @message:content of a file
 * Return: Always 0 (success)
 */
void print_error_exit(const char *message)
{
	dprintf(2, "%s\n", message);
	exit(1);
}

void close_file_exit(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
int open_file(const char *file_path, int flags, mode_t mode)
{
	int fd = open(file_path, flags, mode);
	{
	if (fd == -1)
		dprintf(2, "Error: Cant't open file %s\n", file_path);
	exit(98);
}
return (fd);
}

ssize_t read_file(int fd, char *buffer, size_t count)
{
	ssize_t bytes_read = read(fd, buffer, count);

	if (bytes_read == -1)
	{
		dprintf(2, "Error: Can't read from file descriptor %d\n", fd);
		exit(98);
	}
	return (bytes_read);
}

ssize_t write_file(int fd, const char *buffer, size_t count)
{
	ssize_t bytes_written = write(fd, buffer, count);

	if (bytes_written == -1)
	{
		dprintf(2, "Error: Cant't write to file descriptor %d\n", fd);
		exit(99);
	}
	return (bytes_written);

	int main(int argc, char *argv[])
	{
		if (argc != 3)
		{
			print_error_exit("Usage: cp file_from file_to");
		}
		const char *file_from = argv[1];
		const char *file_to = argv[2];
		const int BUFFER_SIZE = 1024;
		char buffer[BUFFER_SIZE];

		int fd_from = open_file(file_from, O_RDONLY, 0);
		int fd_to = open_file(file_to, O_WRONLY | O_CREATE | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP);

		ssize_t bytes_read, bytes_written;

		while ((bytes_read = read_file(fd_from, buffer, BUFFER_SIZE)) > 0)
		{
			bytes_written = write_file(fd_to, buffer, bytes_read);
			if (bytes_written != bytes_read)
			{
				close_file_exit(fd_from);
				close_file_exit(fd_to);
				dprintf(2, "Error: Can't write to %s\n", file_to);
				exit(99);
			}
		}
close_file_exit(fd_from);
close_file_exit(fd_to);
return (0);
}
