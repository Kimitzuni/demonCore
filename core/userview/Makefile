CFLAGS = -Os -pipe -Wall

all: build


build:
	@gcc userview.c -o userview $(CFLAGS)

install:
	@cp userview /usr/bin/userview

uninstall:
	@rm /usr/bin/userview

clean:
	@rm userview
