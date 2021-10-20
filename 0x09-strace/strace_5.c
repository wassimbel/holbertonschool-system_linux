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
			break;
	}
	return (0);
}

/**
 * print_register - print register
 * @reg: registers struct
 * @i: index
 * @r: register
 * @s: char
 * @pid: id of the process
*/

void print_register(struct user_regs_struct reg,
		    int i, ulong r, char *s, pid_t pid)
{
	char *str;

	if (syscalls_64_g[reg.orig_rax].params[i] != (type_t)-1 &&
	    syscalls_64_g[reg.orig_rax].params[i] != VOID)
	{
		if (syscalls_64_g[reg.orig_rax].params[i] == VARARGS)
			fprintf(stdout, "%s...", s);
		else if (syscalls_64_g[reg.orig_rax].params[i] == CHAR_P)
		{
			str = str_read(pid, r);
			fprintf(stdout, "%s\"%s\"", s, str);
			free(str);
		}
		else if (syscalls_64_g[reg.orig_rax].params[i] == INT)
			fprintf(stdout, "%s%d", s, (int)r);
		else if (syscalls_64_g[reg.orig_rax].params[i] == LONG)
			fprintf(stdout, "%s%ld", s, (long)r);
		else if (syscalls_64_g[reg.orig_rax].params[i] == SIZE_T)
			fprintf(stdout, "%s%lu", s, (ulong)r);
		else if (syscalls_64_g[reg.orig_rax].params[i] == SSIZE_T)
			fprintf(stdout, "%s%ld", s, (long)r);
		else if (syscalls_64_g[reg.orig_rax].params[i] == U64)
			fprintf(stdout, "%s%lu", s, (ulong)r);
		else if (syscalls_64_g[reg.orig_rax].params[i] == UINT32_T)
			fprintf(stdout, "%s%lu", s, (ulong)r);
		else if (syscalls_64_g[reg.orig_rax].params[i] == UNSIGNED_INT)
			fprintf(stdout, "%s%u", s, (uint)r);
		else if (syscalls_64_g[reg.orig_rax].params[i] == UNSIGNED_LONG)
			fprintf(stdout, "%s%lu", s, (ulong)r);
		else if (syscalls_64_g[reg.orig_rax].params[i] == PID_T)
			fprintf(stdout, "%s%d", s, (int)r);
		else
			fprintf(stdout, "%s%#lx", s, r);
	}
}

/**
 * print_args - print arguments to syscalls
 * @reg: registers struct
 * @pid: id of the process
*/
void print_args(struct user_regs_struct reg, pid_t pid)
{
	print_register(reg, 0, reg.rdi, "", pid);
	print_register(reg, 1, reg.rsi, ", ", pid);
	print_register(reg, 2, reg.rdx, ", ", pid);
	print_register(reg, 3, reg.r10, ", ", pid);
	print_register(reg, 4, reg.r8, ", ", pid);
	print_register(reg, 5, reg.r9, ", ", pid);
}

/**
 * tracer - prints syscall name and its return value
 * @pid: id of the process
 * @argc: number args
 * @argv: pointer to array of argv
 * @envp: pointer to environment variables
 * Return: returns 0 on success
 */

int tracer(pid_t pid, int argc, char *argv[], char *envp[])
{
	int status, i;
	struct user_regs_struct reg;
	long retval;

	setbuf(stdout, NULL);
	waitpid(pid, &status, 0);
	ptrace(PTRACE_SETOPTIONS, pid, NULL, PTRACE_O_TRACESYSGOOD);
	if (!sys_call(pid))
		return (1);
	ptrace(PTRACE_GETREGS, pid, 0, &reg);
	if (!sys_call(pid))
		return (1);
	retval = ptrace(PTRACE_PEEKUSER, pid, sizeof(long) * RAX);
	fprintf(stdout, "execve(\"%s\", [", argv[0]);
	for (i = 0; i < argc; ++i)
		printf("%s\"%s\"", i == 0 ? "" : ", ", argv[i]);
	for (i = 0; envp[i]; ++i)
		;
	printf("], [/* %d vars */]) = %#lx\n", i, retval);
	while (1)
	{
		if (!sys_call(pid))
			break;
		ptrace(PTRACE_GETREGS, pid, NULL, &reg);
		fprintf(stdout, "%s(", syscalls_64_g[reg.orig_rax].name);
		print_args(reg, pid);
		if (!sys_call(pid))
			break;
		retval = ptrace(PTRACE_PEEKUSER, pid, sizeof(long) * RAX);
		print_retval(reg, retval);
	}
	fprintf(stdout, ") = ?\n");
	return (0);
}

/**
 * main - entry point
 * @argc: number args
 * @argv: pointer to array of argv
 * @envp: pointer to environment variables
 * Return: 0 on success otherwise EXIT_FAILURE
 */

int main(int argc, char *argv[], char *envp[])
{
	pid_t pid;

	if (argc < 2)
	{
		fprintf(stderr, "%s command [args...]\n", argv[0]);
		return (EXIT_FAILURE);
	}

	pid = fork();
	argv++;
	argc--;
	if (pid < 0)
		return (1);
	if (!pid)
	{
		ptrace(PTRACE_TRACEME);
		kill(getpid(), SIGSTOP);
		return (execve(argv[0], argv, envp));
	}
	else
	return (tracer(pid, argc, argv, envp));
}
