CFLAGS = -Os -pipe -Wall

all: createDir userview

createDir:
	@./bin/createDir

userview:
	@echo "Building 'userview'"
	@gcc core/userview/userview.c -o build/userview $(CFLAGS)

clean:
	rm -rvf build
