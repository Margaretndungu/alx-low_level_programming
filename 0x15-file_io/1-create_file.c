#include "main.h"
/**
 * create_file - Create a function that creates a file.
 * @filename:file name
 * @text_content: is a NULL terminated string to write to the file
 * Return:1 on success, -1 on failure
 * if filename is NULL return -1
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int bytes_Written;

	if (filename == NULL)
	{
		return (-1);
	}

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		bytes_Written = write(fd, text_content, strlen(text_content));
		if (bytes_Written == -1)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}
