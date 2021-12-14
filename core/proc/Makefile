CFLAGS = -Os -pipe -Wall

all: build

build:
	@gcc proc.c -o proc $(CFLAGS)

install:
	@cp proc /usr/bin/proc

uninstall:
	@rm /usr/bin/proc

clean:
	@rm proc
