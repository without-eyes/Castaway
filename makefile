# Compiler and flags
CC = gcc
CFLAGS = -Wall -lmenu -lncurses -I$(IDIR) -g
VFLAGS = --leak-check=full --show-leak-kinds=all
TFLAGS = -lcriterion --coverage -g -O0

# Directories
IDIR = ./include/
SRCDIR = ./src/
TESTDIR = ./test/

# Source and test files
SOURCES = $(wildcard ${SRCDIR}action/*.c) \
		  $(wildcard ${SRCDIR}core/*.c) \
          $(wildcard ${SRCDIR}entities/*.c) \
          $(wildcard ${SRCDIR}stats/*.c)

TESTS = $(filter-out ${SRCDIR}core/main.c, \
        $(SOURCES) \
        $(wildcard ${TESTDIR}action/*.c) \
        $(wildcard ${TESTDIR}entities/*.c) \
        $(wildcard ${TESTDIR}stats/*.c))

# Targets
.PHONY: all memory fullmemory test coverage allclean clean cleantest cleancoverage
.SILENT: all memory fullmemory test coverage allclean

# Main targets
all: castaway run clean
memory: castaway simplecheck clean
fullmemory: castaway fullcheck clean
test: criterion cleantest
coverage: cleancoverage criterion gcovr clean
allclean: cleancoverage cleantest
debug: castaway gdb clean

# Rules
castaway:
	$(CC) $(SOURCES) $(CFLAGS) -o $@

simplecheck:
	valgrind ./castaway

fullcheck:
	valgrind $(VFLAGS) ./castaway

criterion:
	$(CC) $(TESTS) $(CFLAGS) $(TFLAGS) && ./a.out

gcovr:
	gcovr --html-details -o ./test/coverage/coverage.html

gdb:
	gdb ./castaway

run:
	./castaway

cleancoverage:
	rm -f ./test/coverage/*

cleantest:
	rm -f ./a.out ./*.gcda ./*.gcno

clean:
	rm -f castaway
