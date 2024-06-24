CC = gcc
CFLAGS = -Wall -lmenu -lncurses -I$(IDIR) -g

IDIR = ./inclued/
SRCDIR = ./src/

SOURCES = ${SRCDIR}*.c

all: castaway run clean

castaway:
	${CC} ${SOURCES} ${CFLAGS} -o $@

run:
	./castaway

clean:
	rm -f castaway