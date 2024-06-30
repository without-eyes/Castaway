CC = gcc
CFLAGS = -Wall -lmenu -lncurses -I$(IDIR) -g

IDIR = ./include/
SRCDIR = ./src/

SOURCES = ${SRCDIR}core/*.c\
		  ${SRCDIR}entities/*.c\

all: castaway run clean
check: castaway valgrind clean

castaway:
	${CC} ${SOURCES} ${CFLAGS} -o $@

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./castaway

run:
	./castaway

clean:
	rm -f castaway