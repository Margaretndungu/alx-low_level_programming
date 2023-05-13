#include "main.h"
/**
 * display_error - function that displays an error
 * @message:the message to be displayed
 * Return: Always 0 (success)
 */
void display_error(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(98);
}
/**
 * display_elf_header_infor - display information contained in the ELF header
 * @header:ELF header
 * Return: Always 0 (success)
 */
void display_elf_header_infor(const unsigned char *header)
{
	printf("Magic: %02X %02X %02X %02X\n", header[0],
				header[1], header[2], header[3]);
	printf("Class: %s\n", (header[4] == 1) ? "ELF32" : "ELF64");
	printf("Data: %s\n", (header[5] == 1) ? "little endian" : "big endian");
	printf("Version: %d\n", header[6]);
	printf("OS/ABI: %d\n", header[7]);
	printf("ABI Version: %d\n", header[8]);
	printf("Type: %d\n", *(unsigned short *)(header + 16));
	printf("Entry point address: 0x%lx\n", *(unsigned long *)(header + 24));
}
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument count
 * Return: Always 0 (success)
 */
int main(int argc, char *argv[])
{
	int fd;
	const char *filename;
	unsigned char header[ELF_HEADER_SIZE];

	if (argc != 2)
	{
		display_error("Usage: elf_header elf_filename");
	}
	filename = argv[1];
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		display_error("Failed to open the file.");
	}

	if (read(fd, header, ELF_HEADER_SIZE) != ELF_HEADER_SIZE)
	{
		display_error("Failed to read the ELF header.");
	}
	if (!(header[0] == 0x7F && header[1] == 'E' && header[2] == 'L'
					&& header[3] == 'F'))
	{
		display_error("Not a valid ELF file.");
	}
	display_elf_header_infor(header);
	close(fd);
	return (0);
}
