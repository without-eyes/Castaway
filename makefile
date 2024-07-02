CC = gcc
CFLAGS = -Wall -lmenu -lncurses -I$(IDIR) -g
VFLAGS = --leak-check=full --show-leak-kinds=all

IDIR = ./include/
SRCDIR = ./src/

SOURCES = ${SRCDIR}core/*.c\
		  ${SRCDIR}entities/*.c\

all: castaway run clean
memory: castaway simplecheck clean
fullmemory: castaway fullcheck clean

castaway:
	${CC} ${SOURCES} ${CFLAGS} -o $@

simplecheck:
	valgrind ./castaway

fullcheck:
	valgrind ${VFLAGS} ./castaway

run:
	./castaway

clean:
	rm -f castaway test