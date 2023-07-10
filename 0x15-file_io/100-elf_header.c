#include "main.h"
/**
 * display_error - function that displays error message
 * @message:pointer to the error message
 * Return: Nothing
 */
void display_error(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(98);
}
/**
 * display_elf_header - function that describes display of elf header
 * @filename:pointer to the filename
 * Return:Nothing
 */
void display_elf_header(const char *filename)
{
	int fd = open(filename, O_RDONLY);
	ElfHeader header;

	if (fd == -1)
		display_error("Error opening file");

	if (read(fd, &header, sizeof(header)) != sizeof(header))
		display_error("Error reading ELF header");
	if (header.magic[0] != 0x7f || header.magic[1] != 'E' ||
		header.magic[2] != 'L' || header.magic[3] != 'F')
		display_error("Not an ELF file");
	printf("Magic: %02x %c %c %c\n", header.magic[0], header.magic[1],
		header.magic[2], header.magic[3]);
	printf("Class: %u\n", header.class);
	printf("Data: %u\n", header.data);
	printf("Version: %u\n", header.version);
	printf("OS/ABI: %u\n", header.os_abi);
	printf("ABI Version: %u\n", header.abi_version);
	printf("Type: %u\n", header.type);
	printf("Entry point address: 0x%lx\n", header.entry);
	close(fd);
}
/**
 * main - entry point
 * @argc: argument count
 * @argv: pointer to argument vector
 * Return: 0 on success, 1 if an error occurs
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (1);
	}
	display_elf_header(argv[1]);
	return (0);
}
