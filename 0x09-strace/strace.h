#ifndef STRACE_H
#define STRACE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>
#include <sys/reg.h>
#include <sys/stat.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

#define RET 1


int parse_args(int argc, char *argv[]);
int attach(char *args[]);
int step_syscall(pid_t pid);

#endif /* STRACE_H */