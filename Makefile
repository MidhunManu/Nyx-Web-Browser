cc = gcc
cflags = -std=c23 -Wall
src = src/main.c src/platform/x11_window.c
out = nyx

all:
	$(cc) $(cflags) $(src) -o $(out) -lX11
clean:
	rm $(out)

