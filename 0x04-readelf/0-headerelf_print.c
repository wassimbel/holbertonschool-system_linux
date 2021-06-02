#include "_elf.h"

/**
 * print_magic - prints the magic numbers
 * @e_ident: elf array of bytes specifies to interpret the file
 * Return: returns 0
 **/

int print_magic(unsigned char *e_ident)
{
	size_t i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", e_ident[i]);
	putchar('\n');
	return (0);
}

/**
 * print_class - prints the architecture for the binary
 * @e_ident: elf array of bytes specifies to interpret the file
 * Return: returns 0
 **/

int print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("This class is invalid\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("UNKNOWN\n");
		break;
	}

	return (0);
}

/**
 * print_data - prints the data encoding of
 * the processor-specific data int the file
 * @e_ident: elf array of bytes specifies to interpret the file
 * Return: returns 0
 **/

int print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("Unknown data format\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	}
	return (0);
}


/**
 * print_ei_version - prints the version number
 * of the ELF specification
 * @e_ident: elf array of bytes specifies to interpret the file
 * Return: returns 0
 **/

int print_ei_version(unsigned char *e_ident)
{
	printf("  Version:                         ");
	switch (e_ident[EI_VERSION])
	{
	case EV_NONE:
		printf("Invalid version\n")
		break;
	case EV_CURRENT:
		printf("1 (current)\n");
		break;
	}
	return (0);
}

/**
 * print_osabi - prints the operating system and ABI
 * to which the object is targeted
 * @e_ident: elf array of bytes specifies to interpret the file
 * Return: returns 0
 **/

int print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV, ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM architecture\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Stand-alone (embed‐ded)\n");
		break;
	default:
		printf("unknown");
		break;
	}
	return (0);
}
