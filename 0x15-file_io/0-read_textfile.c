#include <stdio.h>
#include <errno.h>
#include "main.h"
/**
 * read_textfile - function that reads a text file and prints
 * it to the POSIX standard output.
 * @letters:number of letters it should read and print
 * @filename: filename
 * Return:actual number of letters it could read and print
 * if the file can not be opened or read, return 0
 * if filename is NULL return 0
 * if write fails or does not write the expected amount of bytes, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *file;
	char *buffer;
	size_t bytesRead, bytesWritten;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		return (0);
	}

	buffer = malloc((letters + 1) * sizeof(char));

	if (buffer == NULL)
	{
		fclose(file);
		return (0);
	}
	if (filename == NULL)
	{
		return (0);
	}
	bytesRead = fread(buffer, sizeof(char), letters, file);

	if (bytesRead != letters)
	{
		fclose(file);
		free(buffer);
		return (0);
	}
	bytesWritten = fwrite(buffer, sizeof(char), bytesRead, stdout);

	if (bytesWritten != bytesRead)
	{
		fclose(file);
		free(buffer);
		return (0);
	}
	fclose(file);
	free(buffer);
	return (bytesRead);
}
