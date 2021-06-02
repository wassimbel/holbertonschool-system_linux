#include "_elf.h"

/**
* print_header_size - prints elf header's size in bytes
* @elf_headers: Elf headers 64 bit
* Return: 0 on success, 1 otherwise
*/
int print_header_size(elf_headers *headers)
{
	printf("  Size of this header:               ");
	if (is_64(elf_headers.e_64))
		printf("%ld (bytes)\n", (long)elf_headers.e_64.e_ehsize);
	else
		printf("%ld (bytes)\n", (long)elf_headers.e_32.e_ehsize);

	return (0);
}

