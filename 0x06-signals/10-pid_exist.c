#include <signal.h>
#include <sys/types.h>

/**
 * pid_exist - tests if a process exists, given its PID
 * correct result when run as root
 * @pid: pid
 * Return: 1 if the process with the PID pid exists, or 0 otherwise
 **/
int pid_exist(pid_t pid)
{
	return (kill(pid, 0) + 1);
}
