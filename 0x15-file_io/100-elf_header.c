#include "main.h"
#include <stdint.h>
#include <fcntl.h>
#include <string.h>
/**
 * elf_header -  program that displays the information
 * contained in the ELF header at the start of an ELF file.
 * @filename: file name
 * Return: Nothing
 */
void elf_header(const char *filename)
{
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		fprintf(stderr, "Error: Failed to open file: %s\n", filename)
			exit(98);
	}
Elf32_Ehdr header;
ssize_t bytes_read = read(fd, &header, sizeof(Elf32_Ehdr));

if (bytes_read != sizeof(Elf32_Ehdr))
{
	fprintf(stderr, "Error: Failed to read ELF header\n");
	exit(98);
}
if (memcmp(header.e_ident, '\x7F''ELF', 4) != 0)
{
	fprintf(stderr, "Error: Not an ELF file\n");
	exit(98);
}
printf("Magic: %02X %02X %02X %02X\n", header.e_ident[0], header.e_ident[1],
	header.e_ident[2], header.e_ident[3]);
printf("Class: %u\n", header.e_ident[EI_CLASS]);
printf("Data: %u\n", header.e_ident[EI_DATA]);
printf("Version: %u\n", header.e_ident[EI_VERSION]);
printf("OS/ABI:%u\n", header.e_indent[EI_OSABI]);
printf("ABI Version: %u\n", header.e_indent[EI_ABIVERSION]);
printf("Type: %u\n", header.e_type);
printf("Entry point address: 0x%08X\n", header.e_entry);

close(fd);
}
/**
 * main - entry point
 * @argc:argument count
 * @argv:argument vector
 * Return: Always 0 (success)
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: elf_header elf_filename\n");
		return (1);
	}
	elf_header(argv[1]);
	return (0);
}
