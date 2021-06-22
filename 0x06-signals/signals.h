#ifndef SIGNALS_H_
#define SIGNALS_H_
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

int handle_signal(void);
void handler(int signum);
void (*current_handler_signal(void))(int);
int handle_sigaction(void);
#endif /* SIGNALS_H_ */
