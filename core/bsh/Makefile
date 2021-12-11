# Makefile for the Basic Shell
# version 1.0
#
# -----------------------------------------
#  bsh: A Painfully POSIX Compliant Shell
# -----------------------------------------
# Developer: rtiannew@gmail.com

CFLAGS = -O2 -w -pipe -march=native

all: build

build:
	@gcc bsh_main.c -o bsh $(CFLAGS)

clean:
	@rm -rvf bsh
