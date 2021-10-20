#ifndef STRACE_H
#define STRACE_H

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>
#include <sys/reg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/user.h>
#include "syscalls.h"

char *str_read(pid_t pid, unsigned long address);
void print_retval(struct user_regs_struct reg, long retval);

#endif /* STRACE_H */
