#include "_elf.h"

/**
 * print_entry - prints the virtual address to which
 * the system first transfers control
 * @headers: header elf struct
 * Return: returns 0
 **/

int print_entry(elf_headers *headers)
{
if (identify_architecture(headers.Ehdr64.e_ident) == 2)
	printf("Entry point address:            0x%x\n", headers.Ehdr64.e_entry);
else if (identify_architecture(headers.Ehdr32.e_ident) == 1)
	printf("Entry point address:            0x%x\n", headers.Ehdr32.e_entry);
return (0);
}


/**
 * print_prog_headers - prints the the program header
 * tables's file offset in bytes
 * @headers: header elf struct
 * Return: returns 0
 **/

int print_prog_headers(elf_headers *headers)
{
if (identify_architecture(headers.Ehdr64.e_ident) == 2)
	printf("Start of program headers:            %d (bytes into file)\n",
		headers.Ehdr64.e_phoff);
else if (identify_architecture(headers.Ehdr32.e_ident) == 1)
	printf("Start of program headers:            %d (bytes into file)\n",
		headers.Ehdr32.e_phoff);
return (0);
}

/**
 * print_section_headers - prints the sections header
 * table's file offset in bytes
 * @headers: header elf struct
 * Return: returns 0
 **/

int print_section_headers(elf_headers *headers)
{
if (identify_architecture(headers.Ehdr64.e_ident) == 2)
	printf("Start of section headers:            %d (bytes into file)\n",
		headers.Ehdr64.e_shoff);
else if (identify_architecture(headers.Ehdr32.e_ident) == 1)
	printf("Start of section headers:            %d (bytes into file)\n",
		headers.Ehdr32.e_shoff);
return (0);
}

/**
 * print_flags - prints processor-specific flags
 * associated with the file
 * @e_flags: member of elf header
 * Return: returns 0
 **/

int print_flags(uint32_t e_flags)
{
	printf("Flags:                               0x%x".e_flags);
	return (0);
}
