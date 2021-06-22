#include "signals.h"

/**
 * main - prints a description of a given signal
 * @ac: arguments counter
 * @argv: array of arguments
 * Return: EXIT_SUCCESS on success otherwise EXIT_FAILURE
 **/

int main(int ac, char *argv[])
{
	if (ac != 2)
	{
		printf("Usage : %s <signum>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	printf("%d: %s\n", atoi(argv[1]), strsignal(atoi(argv[1])));
	return (EXIT_SUCCESS);
}
