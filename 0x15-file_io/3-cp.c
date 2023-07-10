#include "main.h"
/**
 * error - function describes error
 * @message:pointer to the message
 * @exitCode:describes the exit
 * Return: Nothing
 */
void error(const char *message, int exitCode)
{
	write(STDERR_FILENO, message, strlen(message));
	exit(exitCode);
}
/**
 * openFile - function that describes the openfile
 * @filename:pointer to the file
 * @flags:describes flags in integer
 * @mode:describes the mode of the file
 * Return:file descriptor
 */
int openFile(const char *filename, int flags, mode_t mode)
{
	int fd = open(filename, flags, mode);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(98);
	}
	return (fd);
}
/**
 * copyFile - function that describe copying of a file
 * @fileFrom:pointer to source of a file
 * @fileTo:pointer to destination file
 * Return:0 on success 1 on failure
 */
void copyFile(const char *fileFrom, const char *fileTo)
{
	int fdFrom = openFile(fileFrom, O_RDONLY, 0);
	int fdTo = openFile(fileTo, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	char buffer[BUFFER_SIZE];
	ssize_t bytesRead, bytesWritten;

while ((bytesRead = read(fdFrom, buffer, BUFFER_SIZE)) > 0)
{
	bytesWritten = write(fdTo, buffer, bytesRead);
	if (bytesWritten == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", fileTo);
	exit(99);
	}
}
if (bytesRead == -1)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", fileFrom);
	exit(98);
}
if (close(fdFrom) == -1)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fdFrom);
	exit(100);
}
if (close(fdTo) == -1)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fdTo);
	exit(100);
}
}
/**
 * main - entry point
 * @argc:argument count
 * @argv: pointer to character in argument vector
 * Return:0 on success
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		error("Usage: cp file_from file_to\n", 97);
	}
	copyFile(argv[1], argv[2]);
	exit(0);
}
