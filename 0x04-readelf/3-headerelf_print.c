#include "_elf.h"

/**
 * print_header_size - prints elf header's size in bytes
 * @headers: Elf headers 64 bit
 * Return: 0 on success, 1 otherwise
 **/

int print_header_size(elf_headers *headers)
{
	printf("  Size of this header:               ");
	if (identify_architecture(headers.Ehdr64.e_ident) == 2)
		printf("%d (bytes)\n", headers.Ehdr64.e_ehsize);
	else if ((identify_architecture(headers.Ehdr32.e_ident) == 1)
		printf("%d (bytes)\n", headers.Ehdr32.e_ehsize);
	return (0);
}

/**
 * print_prog_size - prints elf program one entry size in bytes
 * @headers: Elf headers 64 bit
 * Return: 0 on success, 1 otherwise
**/

int print_prog_size(elf_headers *headers)
{
	printf("  Size of program headers:               ");
	if (identify_architecture(headers.Ehdr64.e_ident) == 2)
		printf("%d (bytes)\n", headers.Ehdr64.e_phentsize);
	else if ((identify_architecture(headers.Ehdr32.e_ident) == 1)
		printf("%d (bytes)\n", headers.Ehdr32.e_phentsize);
	return (0);
}
