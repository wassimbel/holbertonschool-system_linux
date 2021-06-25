#include "signals.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/**
 * handle_signal - sets a handler for the signal SIGINT
 * Return: returns 0 on success, or -1 on error
 **/

int handle_signal(void)
{
	if (signal(SIGINT, handler) == SIG_ERR)
		return (-1);
	return (0);
}

/**
 * handler - handler for SIGINT
 * @signum: signal number
 **/

void handler(int signum)
{
	printf("Gotcha! [%d]\n", signum);
	fflush(stdout);
}
