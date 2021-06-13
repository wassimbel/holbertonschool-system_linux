#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "aa"
#define S2  ""
#define S3  "azzz"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	char *s1 = "a";
	char *s2 = "z";
	int i;

    i = asm_strcmp(s1, s2);
    assert(strcmp(S1, S2) == asm_strcmp(S1, S2));
    assert(strcmp(S1, S3) == asm_strcmp(S1, S3));

	printf("%d\n", i);
    printf("All good!\n");
    return (EXIT_SUCCESS);
}
