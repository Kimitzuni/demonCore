CFLAGS = -Os -pipe -Wall

all: build

build:
	@gcc cwd.c -o cwd $(CFLAGS)

install:
	@cp cwd /usr/bin/cwd

uninstall:
	@rm /usr/bin/cwd

clean:
	@rm cwd
