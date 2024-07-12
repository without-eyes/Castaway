CC = gcc
CFLAGS = -Wall -lmenu -lncurses -I$(IDIR) -g
VFLAGS = --leak-check=full --show-leak-kinds=all
TFLAGS = -lcriterion --coverage -g -O0

IDIR = ./include/
SRCDIR = ./src/
TESTDIR = ./test/

SOURCES = ${SRCDIR}core/*.c\
		  ${SRCDIR}entities/*.c

TESTS = $(filter-out ./src/core/main.c,\
		$(wildcard ${SRCDIR}core/*.c\
        ${SRCDIR}entities/*.c\
        ${TESTDIR}core/*.c\
        ${TESTDIR}entities/*.c))

.SILENT:
all: castaway run clean
memory: castaway simplecheck clean
fullmemory: castaway fullcheck clean
test: cleantest criterion cleantest
coverage: clean cleancoverage criterion gcovr clean
allclean: clean cleancoverage cleantest

castaway:
	${CC} ${SOURCES} ${CFLAGS} -o $@

simplecheck:
	valgrind ./castaway

fullcheck:
	valgrind ${VFLAGS} ./castaway

criterion:
	${CC} ${TESTS} ${CFLAGS} ${TFLAGS} && ./a.out

gcovr:
	gcovr --html-details -o ./test/coverage/coverage.html

run:
	./castaway

cleancoverage:
	rm -f ./test/coverage/*

cleantest:
	rm -f ./a.out ./*.gcda ./*.gcno

clean:
	rm -f castaway