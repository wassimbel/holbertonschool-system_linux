#ifndef _ELF_H
#define _ELF_H
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

/**
 * struct self - elf structures
 * @Ehdr32: ELF header structure for 32-bit architecture
 * @Ehdr64: ELF header structure for 64-bit architecture
 * @Phdr32: ELF program header structure for 32-bit architecture
 * @Phdr64: ELF program header structure for 32-bit architecture
 * @Shdr32: ELF section header structure for 32-bit architecture
 * @Shdr64: ELF section header structure for 32-bit architecture
 **/

typedef struct elf
{
	Elf32_Ehdr *Ehdr32;
	Elf64_Ehdr *Ehdr64;
	Elf32_Phdr *Phdr32;
	Elf64_Phdr *Phdr64;
	Elf32_Shdr *Shdr32;
	Elf64_Shdr *Shdr64;
} elf_headers


int check_elf(unsigned char *e_ident);
int identify_architecture(unsigned char *e_ident);

int print_magic(unsigned char *e_ident);
int print_class(unsigned char *e_ident);
int print_data(unsigned char *e_ident);
int print_ei_version(unsigned char *e_ident);
int print_osabi(unsigned char *e_ident);
int print_entry(
int print_entry(elf_headers *headers);
int print_prog_headers(elf_headers *headers);
int print_section_headers(elf_headers *headers);
int print_flags(uint32_t e_flags);
int print_header_size(elf_headers *headers);
int print_prog_size(elf_headers *headers);

#endif /* _ELF_H */
