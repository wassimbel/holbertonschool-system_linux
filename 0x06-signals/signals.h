#ifndef SIGNALS_H_
#define SIGNALS_H_
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int handle_signal(void);
void handler(int signum);
void (*current_handler_signal(void))(int);
int handle_sigaction(void);
void (*current_handler_sigaction(void))(int);
int trace_signal_sender(void);
void handler1(int signum, siginfo_t *info, void *ptr);

#endif /* SIGNALS_H_ */
