#ifndef _ELF_H
#define _ELF_H
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

typedef struct
{
	Elf32_Ehdr *Ehdr32;
	Elf64_Ehdr *Ehdr64;
	Elf32_Phdr *Phdr32;
	Elf64_Phdr *Phdr64;
	Elf32_Shdr *Shdr32;
	Elf64_Shdr *Shdr64;
} elf_headers




#endif /* _ELF_H */
