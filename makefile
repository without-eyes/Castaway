CC = gcc
CFLAGS = -Wall -lmenu -lncurses -I$(IDIR) -g

IDIR = ./include/
SRCDIR = ./src/

SOURCES = ${SRCDIR}core/*.c\
		  ${SRCDIR}entities/*.c\

all: castaway run clean

castaway:
	${CC} ${SOURCES} ${CFLAGS} -o $@

run:
	./castaway

clean:
	rm -f castaway