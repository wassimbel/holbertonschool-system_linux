#include "multithreading.h"

/**
 * thread_entry -  serves as the entry point to a new thread
 * @arg: holds the address of a string that must be printed
 * Return: The pthread_exit() function cannot return to its caller.
*/

void *thread_entry(void *arg)
{
	if (!arg)
		return (NULL);
	printf("%s\n", (char *)arg);
	pthread_exit(0);
}
