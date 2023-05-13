#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <elf.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024
#define ELF_HEADER_SIZE 64

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);
void print_error(const char *error_message);
void copy_file(const char *file_from, const char *file_to);
int main(int argc, char *argv[]);
void display_error(const char *message);
void display_elf_header_info(const unsigned char *header);
int main(int argc, char *argv[]);
#endif
