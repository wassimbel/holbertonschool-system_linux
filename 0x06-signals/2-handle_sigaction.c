#include "signals.h"

/**
 * handle_sigaction - sets a handler for the signal SIGINT
 * Return: return 0 on success, or -1 on error
 **/

int handle_sigaction(void)
{
	struct sigaction act;

	act.sa_handler = handler;

	return (sigaction(SIGINT, &act, NULL));
}

/**
 * handler - handler for SIGINT
 * @signum: signal number
 **/

void handler(int signum)
{
        printf("Gotcha! [%d]\n", signum);
}
