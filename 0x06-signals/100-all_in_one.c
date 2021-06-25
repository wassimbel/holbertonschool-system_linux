#include "signals.h"

/**
 * all_in_one -  sets up a single handler for all the signals
 **/

void all_in_one(void)
{
	struct sigaction act;
	int i;

	act.sa_sigaction = handler4;
	act.sa_flags = SA_SIGINFO;
	for (i = 1; i <= SIGRTMAX; i++)
		sigaction(i, &act, NULL);
}

/**
 * handler4 - hadnler for all signals
 * @signum: signal number
 * @info: pointer to struct containing signal info
 * @ptr: void ptr
 **/

void handler4(int signum, siginfo_t *info, void *ptr)
{
	(void)signum;
	(void)ptr;
	psiginfo(info, "Caught");
}
