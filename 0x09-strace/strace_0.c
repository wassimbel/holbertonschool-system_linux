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
 * parse_args - check for usage args
 * @argc: number of arguments
 * @argv: pointer to array of argv
 * Return: 0 on success, 1 on error
 */

int parse_args(int argc, char *argv[])
{
	struct stat sb;

	if (argc < 2)
	{
		fprintf(stderr, "%s command [args...]\n", *argv);
		return (1);
	}
	if (stat(argv[1], &sb) == -1)
	{
		fprintf(stderr, "%s: Can't stat '%s': No such file or directory\n",
				*argv, argv[1]);
		return (1);
	}
	return (0);
}

/**
 * main - entry point
 * @argc: number args
 * @argv: pointer to array of argv
 * Return: 0 on success otherwise 1
 */

int main(int argc, char *argv[])
{
	pid_t pid;

	if (parse_args(argc, argv))
		return (1);

	pid = fork();

	if (pid < 0)
		return (1);
	if (!pid)
		return (attach(argv + 1) == -1);
	tracer(pid);
	return (0);
}
