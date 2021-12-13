CFLAGS = -Os -pipe -Wall

all: build

build:
	@gcc fileout.c -o fileout $(CFLAGS)

install:
	@cp fileout /usr/bin/fileout

uninstall:
	@rm /usr/bin/fileout

clean:
	@rm fileout
