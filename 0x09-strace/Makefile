CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

SRC = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRC))
HELPER = $(patsubst %.c, %.o, func_helper.c)
0 = $(patsubst %.c, %.o, $(wildcard *_0.c))
1 = $(patsubst %.c, %.o, $(wildcard *_1.c))
2 = $(patsubst %.c, %.o, $(wildcard *_2.c))
3 = $(patsubst %.c, %.o, $(wildcard *_3.c))
4 = $(patsubst %.c, %.o, $(wildcard *_4.c)) $(HELPER)
5 = $(patsubst %.c, %.o, $(wildcard *_5.c)) $(HELPER)
.PHONY: strace_0 strace_1 strace_2.c strace_3.c strace_4.c strace_5.c clean

strace_0: $(0)
	$(CC) $(CFLAGS) $(0) -o strace_0

strace_1: $(1)
	$(CC) $(CFLAGS) $(1) -o strace_1

strace_2: $(2)
	$(CC) $(CFLAGS) $(2) -o strace_2

strace_3: $(3)
	$(CC) $(CFLAGS) $(3) -o strace_3
strace_4: $(4)
	$(CC) $(CFLAGS) $(4) -o strace_4
strace_5: $(5)
	$(CC) $(CFLAGS) $(5) -o strace_5
clean:
	rm -f $(OBJS) strace_*
