#include "multithreading.h"
#include <stdarg.h>

/**
 * tprintf - uses the printf family to print out a given formatted string.
 * @format: string format
 * Return: returns EXIT_SUCCESS
 **/

int tprintf(char const *format, ...)
{
	va_list args;

	va_start(args, format);
	printf("[%lu] ", pthread_self());
	vprintf(format, args);
	va_end(args);
	return (EXIT_SUCCESS);
}
