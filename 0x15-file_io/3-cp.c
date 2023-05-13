#include "main.h"
/**
 * print_error - function that print an error
 * @error_message: pointer to a const character
 * Return: Nothing
 */
void print_error(const char *error_message)
{
	dprintf(STDERR_FILENO, "%s\n", error_message);
	exit(1);
}
/**
 * copy_file - function that copy file from the source to the destination
 * @file_from:source file
 * @file_to:destination file
 * Return: Nothing
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		print_error("Error: Can't read from file");

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_to == -1)
		print_error("Error: Can't writr to file");

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
			print_error("Error: Cant't write to file");
	}

	if (bytes_read == -1)
		print_error("Error: Can't read from file");

	if (close(fd_from) == -1)
		print_error("Error: Can't close file descriptor");
	if (close(fd_to) == -1)
		print_error("Error: Can't close file descriptor");
}
/**
 * main - entry point
 * @argc:argument count
 * @argv:argument vector
 * Return: Nothing
 */
int main(int argc, char *argv[])
{
	const char *file_from;
	const char *file_to;

	if (argc != 3)
	{
		print_error("Usage: cp file_from file_to");
	}

	file_from = argv[1];
	file_to = argv[2];

	copy_file(file_from, file_to);
	return (0);
}
