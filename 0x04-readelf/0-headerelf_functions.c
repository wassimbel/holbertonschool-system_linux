#include "_elf.h"

/**
 * check_elf - checks if a given file is in elf format
 * @e_ident: array of bytes specifies to interpret the file
 * Return: returns 1 if file is elf otherwise 0
 **/

int check_elf(unsigned char *e_ident)
{
	if (e_ident[EI_MAG0] == ELMAG0 && e_ident[EI_MAG1] == ELMAG1
		&& e_ident[EI_MAG2] == ELMAG2  && e_ident[EI_MAG3] == ELMAG3)
		return (1);
	return (0);
}


/**
 * identify_architecture - identifies the architecture for the binary
 * @e_ident: array of bytes specifies to interpret the file
 * Return: returns 1 if 32-bit, 2 if 64-bit otherwise 0
 **/

int identify_architecture(unsigned char *e_ident)
{
	if (e_ident[EI_CLASS] == ELFCLASS32)
		return (1);
	else if (e_ident[EI_CLASS] == ELFCLASS64)
		return (2);
	fprintf(stderr, "invalid architecture\n")
	exit(1);
	return (0);
}


