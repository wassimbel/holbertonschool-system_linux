CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

SRC = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRC))
0 = $(patsubst %.c, %.o, $(wildcard *_0.c))

.PHONY: strace_0 strace_1 strace_2 strace_3 clean

strace_0: $(0)
	$(CC) $(CFLAGS) $(0) -o strace_0

clean:
	rm -f $(OBJS) strace_*
