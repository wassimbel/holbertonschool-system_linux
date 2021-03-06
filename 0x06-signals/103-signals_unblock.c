#include "signals.h"

/**
 * sigset_init -  initializes a sigset
 * @set: a pointer to the signal set to initialize
 * @signals: array of int, each one being a signal number
 * Return: 0 on success, or -1 on error
 **/

int sigset_init(sigset_t *set, int *signals)
{
	int i;

	if (sigemptyset(set) == -1)
		return (-1);

	for (i = 0; signals[i]; i++)
	{
		if (sigaddset(set, signals[i]) == -1)
			return (-1);
	}
	return (0);
}

/**
 * signals_unblock - unblock a given set of signals
 * from being delivered to the current process
 * @signals: array of int, each one being a signal to unblock
 * Return: 0 on success, or -1 on error
 **/

int signals_unblock(int *signals)
{
	sigset_t set;

	if (sigset_init(&set, signals) == -1)
		return (-1);
	return (sigprocmask(SIG_UNBLOCK, &set, NULL));
}
