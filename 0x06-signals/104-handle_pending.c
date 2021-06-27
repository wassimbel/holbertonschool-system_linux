#include "signals.h"

/**
 * handle_pending - sets up a handler for all the pending signals
 * of the current process
 * @handler: pointer to the handler function to set for the pending signals
 * Return: 0 on success, or -1 on error
 **/

int handle_pending(void (*handler)(int))
{
	struct sigaction act;
	sigset_t set;
	int i;

	act.sa_handler = handler;
	act.sa_mask = 
	if (sigpending(&set) == -1)
		return (-1);

	for (i = 1; i <= SIGRTMAX; i++)
	{
		if (sigismember(&set, i))
		if (sigaction(i, &act, NULL) == -1)
			return (-1);
	}
	return (0);
}
