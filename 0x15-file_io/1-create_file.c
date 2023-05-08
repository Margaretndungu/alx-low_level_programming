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
	struct stat st;
	int fd;

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
		size_t len = strlen(text_content);
		ssize_t bytes_written = write(fd, text_content, len);

		if (bytes_written != (ssize_t) len)
		{
			close(fd);
			return (-1);
		}
	}

	if (fstat(fd, &st) == -1)
	{
		close(fd);
		return (-1);
	}
	if ((st.st_mode & S_IRUSR) == 0 || (st.st_mode & S_IWUSR) == 0)
		{
		if (fchmod(fd, S_IRUSR | S_IWUSR) == -1)
			{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}
