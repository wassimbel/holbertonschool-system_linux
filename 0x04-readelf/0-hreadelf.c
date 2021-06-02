#include <_elf.h>

/**
 *
 *
 *
 **/

int main(int ac , char **argv)
{
	File *fp;

	if (ac != 2)
	{
		fprintf(stderr, "Error: Usage 0-hreadelf elf_filename ");
		return (NULL);
	}

	fp = fopen(argv[1], "rb");

	if (!fp)
	{
		fprintf(stderr, "%s: Error: '%s': No such file\n", argv[0],
				argv[1]);
		return (NULL);
	}






}
