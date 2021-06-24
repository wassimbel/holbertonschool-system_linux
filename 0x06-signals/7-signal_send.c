#include "signals.h"

/**
 * main -  sends the signal SIGINT to a process, given its PID
 * @ac: argument counter
 * @argv: array of arguments
 * Return: EXIT_SUCCESS ON success otherwise EXIT_FAILURE
 **/

int main(int ac, char *argv[])
{
	if (ac != 2)
	{
		printf("Usage: %s <pid>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (kill(atoi(argv[1]), SIGINT) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
