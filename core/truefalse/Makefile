CFLAGS = -Os -pipe -Wall

all: build

build:
	@gcc true.c -o true $(CFLAGS)
	@gcc false.c -o false $(CFLAGS)

clean:
	@rm true false
