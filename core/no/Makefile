CFLAGS = -Os -pipe -Wall

all: build


build:
	@gcc no.c -o no $(CFLAGS)

install:
	@cp no /usr/bin/no

uninstall:
	@rm /usr/bin/no

clean:
	@rm no
