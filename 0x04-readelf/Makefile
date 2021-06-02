CC       = gcc
CFLAGS   = -Wall -Werror -Wextra -pedantic
SRC      = $(wildcard *.c)
OBJS     = $(patsubst %.c, %.o, $(SRC))
0        = $(patsubst %.c, %.o, $(wildcard 0-*.c))


0-headerelf: $(0)
	$(CC) $(CFLAGS) $(0) -o 0-hreadelf
