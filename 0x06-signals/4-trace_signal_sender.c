#include "signals.h"

/**
 * trace_signal_sender - defines a handler for the signal
 * SIGQUIT (Control-\ in a shell)
 * Return: return 0 on success, or -1 on error
 **/

int trace_signal_sender(void)
{
	struct sigaction act;

	act.sa_sigaction = handler1;
	act.sa_flags = SA_SIGINFO;

	return (sigaction(SIGQUIT, &act, NULL));
}

/**
 * handler1 - hadnler for the signal SIGQUIT
 * @signum: signal number
 * @info: pointer to struct containing signal info
 * @ptr: void ptr
 **/

void handler1(int signum, siginfo_t *info, void *ptr)
{
	(void) signum;
	(void) ptr;
	printf("SIGQUIT sent by %u\n", info->si_pid);
}
