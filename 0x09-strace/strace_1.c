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
 * tracer - traces process and prints syscall number
 * @pid: id of process to trace
 */
void tracer(pid_t pid)
{
	int status;

	setbuf(stdout, NULL);
	waitpid(pid, &status, 0);
	ptrace(PTRACE_SETOPTIONS, pid, 0, PTRACE_O_TRACESYSGOOD);
	while (1)
	{
		if (!sys_call(pid))
			break;
		printf("%li\n", ptrace(PTRACE_PEEKUSER, pid, sizeof(long) * ORIG_RAX));
		if (!sys_call(pid))
			break;
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
 * trace_name - trace process and prints syscall name
 * @pid: id of the process
 */

void trace_name(pid_t pid)
{
	int status;
	long num;

	setbuf(stdout, NULL);
	waitpid(pid, &status, 0);
	ptrace(PTRACE_SETOPTIONS, pid, 0, PTRACE_O_TRACESYSGOOD);
	while (1)
	{
		if (!sys_call(pid))
			break;
		num = ptrace(PTRACE_PEEKUSER, pid, sizeof(long) * ORIG_RAX);
		printf("%s", syscalls_64_g[num].name);
		if (!sys_call(pid))
			break;
		putchar('\n');
	}
	putchar('\n');
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
	trace_name(pid);
	return (0);
}
