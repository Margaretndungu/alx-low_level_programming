#ifndef MAIN_H
#define MAIN_H

#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<stdio.h>

#define BUFFER_SIZE 1024

typedef struct {
	unsigned char magic[4];
	unsigned char class;
	unsigned char data;
	unsigned char version;
	unsigned char os_abi;
	unsigned char abi_version;
	unsigned char pad[7];
	unsigned short type;
	unsigned short machine;
	unsigned int version2;
	unsigned long entry;
	unsigned long phoff;
	unsigned long shoff;
	unsigned int flags;
	unsigned short ehsize;
	unsigned short phentsize;
	unsigned short phnum;
	unsigned short shentsize;
	unsigned short shnum;
	unsigned short shstrndx;
} ElfHeader;

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);

#endif
