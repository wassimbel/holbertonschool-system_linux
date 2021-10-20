#include "strace.h"

/**
 * str_read - returns a pointer to the string stored in address
 * @pid: id of the process
 * @address: address of str
 * Return: pointer to str
 */
char *str_read(pid_t pid, unsigned long address)
{
	char *s = malloc(4096);
	unsigned int mem = 4096;
	unsigned long i = 0, j;

	while (1)
	{
		if (i + sizeof(j) > mem)
		{
			mem *= 2;
			s = realloc(s, mem);
		}
		j = ptrace(PTRACE_PEEKDATA, pid, address + i);
		if (errno != 0)
		{
			s[i] = 0;
			break;
		}
		memcpy(s + i, &j, sizeof(j));
		if (memchr(&j, 0, sizeof(j)) != NULL)
			break;
		i += sizeof(j);
	}
	return (s);
}

/**
 * print_retval - prints arguments of return value
 * @retval: return value yscall
 * @reg: registers struct
 */
void print_retval(struct user_regs_struct reg, long retval)
{
	char *s = ") = ";

	switch (syscalls_64_g[reg.orig_rax].ret)
	{
	case INT:
		fprintf(stdout, "%s%d\n", s, (int)retval);
		break;
	case SIZE_T:
		fprintf(stdout, "%s%lu\n", s, (ulong)retval);
		break;
	case SSIZE_T:
		fprintf(stdout, "%s%ld\n", s, (long)retval);
		break;
	case LONG:
		fprintf(stdout, "%s%ld\n", s, (long)retval);
		break;
	case U64:
		fprintf(stdout, "%s%lu\n", s, (ulong)retval);
		break;
	case UINT32_T:
		fprintf(stdout, "%s%lu\n", s, (ulong)retval);
		break;
	case UNSIGNED_INT:
		fprintf(stdout, "%s%u\n", s, (uint)retval);
		break;
	case UNSIGNED_LONG:
		fprintf(stdout, "%s%lu\n", s, (ulong)retval);
		break;
	case PID_T:
		fprintf(stdout, "%s%d\n", s, (int)retval);
		break;
	default:
		fprintf(stdout, "%s%#lx\n", s, retval);
}
}
