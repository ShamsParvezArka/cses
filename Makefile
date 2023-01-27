CC = gcc
CFLAGS = -Wall -Wextra -Wformat -ggdb -lm

output: main.c
	$(CC) -o a.out main.c $(CFLAGS)
