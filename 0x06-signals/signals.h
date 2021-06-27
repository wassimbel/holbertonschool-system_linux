#ifndef SIGNALS_H_
#define SIGNALS_H_
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
int handle_signal(void);
void handler(int signum);
void (*current_handler_signal(void))(int);
int handle_sigaction(void);
void (*current_handler_sigaction(void))(int);
int trace_signal_sender(void);
void handler1(int signum, siginfo_t *info, void *ptr);
void handler2(int signum);
int pid_exist(pid_t pid);
void all_in_one(void);
void handler4(int signum, siginfo_t *info, void *ptr);
int sigset_init(sigset_t *set, int *signals);
int signals_block(int *signals);
int signals_unblock(int *signals);
#endif /* SIGNALS_H_ */
