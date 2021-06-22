#include "signals.h"

/**
 * main - sets a handler for the signal SIGINT,
 * and exits right after the signal is received and handled
 * Return: EXIT_SUCCESS on success otherwise EXIT_FAILURE
 **/

int main(void)
{
	if (signal(SIGINT, handler2) == SIG_ERR)
		return (EXIT_FAILURE);
	if (pause() == -1)
		printf("Signal received\n");
	return (EXIT_SUCCESS);
}

/**
 * handler2 - handler for SIGINT
 * @signum: signal number
 **/

void handler2(int signum)
{
	printf("Caught %d\n", signum);
}
