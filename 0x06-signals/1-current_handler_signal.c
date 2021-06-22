#include "signals.h"

/**
 * current_handler_signal - Retrieves current handler of the signal SIGINT
 * Return: pointer to current SIGINT handler, or NULL on failure
 **/

void (*current_handler_signal(void))(int)
{
	void (*handler)(int);

	handler = signal(SIGINT, SIG_DFL);

	if (signal(SIGINT, handler) == SIG_ERR || handler == SIG_ERR)
		return (NULL);
	return (handler);
}
