cc = gcc
cflags = -std=c23 -Wall
src = src/main.c
out = nyx

all:
	$(cc) $(cflags) $(src) -o $(out) -lX11
clean:
	rm $(out)

