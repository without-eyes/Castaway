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
SOURCES = $(wildcard ${SRCDIR}core/*.c) \
          $(wildcard ${SRCDIR}entities/*.c)

TESTS = $(filter-out ${SRCDIR}core/main.c, \
         $(wildcard ${SRCDIR}core/*.c) \
         $(wildcard ${SRCDIR}entities/*.c) \
         $(wildcard ${TESTDIR}core/*.c) \
         $(wildcard ${TESTDIR}entities/*.c))

# Targets
.PHONY: all memory fullmemory test coverage allclean clean cleantest cleancoverage
.SILENT: all memory fullmemory test coverage allclean

# Main targets
all: castaway run clean
memory: castaway simplecheck clean
fullmemory: castaway fullcheck clean
test: cleantest criterion cleantest
coverage: clean cleancoverage criterion gcovr clean
allclean: clean cleancoverage cleantest

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

run:
	./castaway

cleancoverage:
	rm -f ./test/coverage/*

cleantest:
	rm -f ./a.out ./*.gcda ./*.gcno

clean:
	rm -f castaway
