#include "syscalls.h"
#include "strace.h"

/**
 * sys_call - waits for syscall
 * @pid: id of the process
 * Return: 1 if the process is stopped by signal otherwise 0
 */

int sys_call(pid_t pid)
{
	int status;

	while (1)
	{
		ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
		waitpid(pid, &status, 0);
		if (WIFSTOPPED(status) && WSTOPSIG(status) & 0x80)
			return (1);
		if (WIFEXITED(status))
			return (0);
	}
}

/**
 * attach - attach tracer process to specified tracee
 * @args: pointer to array of arguments
 * Return: return -1 on failure
 */
int attach(char *args[])
{
	if (ptrace(PTRACE_TRACEME) == -1)
		return (-1);
	kill(getpid(), SIGSTOP);
	return (execvp(*args, args));
}

/**
 * print_register - print register
 * @reg: registers struct
 * @i: index
 * @r: register
 * @s: char
*/

void print_register(struct user_regs_struct reg,
		    int i, ulong r, char *s)
{
	if (syscalls_64_g[reg.orig_rax].params[i] != (type_t)-1 &&
	    syscalls_64_g[reg.orig_rax].params[i] != VOID)
	{
		if (syscalls_64_g[reg.orig_rax].params[i] == VARARGS)
			fprintf(stdout, "%s...", s);
		else
			fprintf(stdout, "%s%#lx", s, r);
	}
}

/**
 * print_args - print arguments to syscalls
 * @reg: registers struct
*/
void print_args(struct user_regs_struct reg)
{
	print_register(reg, 0, reg.rdi, "");
	print_register(reg, 1, reg.rsi, ", ");
	print_register(reg, 2, reg.rdx, ", ");
	print_register(reg, 3, reg.r10, ", ");
	print_register(reg, 4, reg.r8, ", ");
	print_register(reg, 5, reg.r9, ", ");
}

/**
 * tracer - prints syscall name and its value
 * @pid: id of the process
 * Return: returns 0 on success
 */

int tracer(pid_t pid)
{
	int status;
	struct user_regs_struct reg;

	setbuf(stdout, NULL);
	waitpid(pid, &status, 0);
	ptrace(PTRACE_SETOPTIONS, pid, NULL, PTRACE_O_TRACESYSGOOD);
	while (1)
	{
		if (!sys_call(pid))
			break;
		ptrace(PTRACE_GETREGS, pid, NULL, &reg);
		fprintf(stdout, "%s(", syscalls_64_g[reg.orig_rax].name);
		print_args(reg);
		if (!sys_call(pid))
			break;
		ptrace(PTRACE_GETREGS, pid, NULL, &reg);
		fprintf(stdout, ") = %#lx\n", (ulong)reg.rax);
	}
	fprintf(stdout, ") = ?\n");
	return (0);
}

/**
 * main - entry point
 * @argc: number args
 * @argv: pointer to array of argv
 * Return: 0 on success otherwise EXIT_FAILURE
 */

int main(int argc, char *argv[])
{
	pid_t pid;

	if (argc < 2)
	{
		fprintf(stderr, "%s command [args...]\n", argv[0]);
		return (EXIT_FAILURE);
	}

	pid = fork();
	if (pid < 0)
		return (1);
	if (!pid)
		return (attach(argv + 1) == -1);
	tracer(pid);
	return (0);
}
