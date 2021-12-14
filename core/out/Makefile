CFLAGS = -Os -pipe -Wall

all: build

build:
	@gcc out.c -o out $(CFLAGS)

install:
	@cp out /usr/bin/out

uninstall:
	@rm /usr/bin/out

clean:
	@rm out
