#include "signals.h"

/**
 * current_handler_sigaction -  retrieves the current handler
 * of the signal SIGINT
 * Return: returns a pointer to the current handler of SIGINT,
 * or NULL on failure
 **/

void (*current_handler_sigaction(void))(int)
{
	struct sigaction old;

	if (sigaction(SIGINT, NULL, &old) == -1)
		return (NULL);
	return (old.sa_handler);
}
