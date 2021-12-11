CFLAGS = -Os -pipe -Wall

all: createDir userview bsh

createDir:
	[[ ! -d build ]] && mkdir build || DIREXISTS=1

userview:
	@echo "Building 'userview'"
	@gcc core/userview/userview.c -o build/userview $(CFLAGS)

bsh:
	@echo "Building 'bsh'"
	@gcc core/bsh/bsh_main.c -o build/bsh $(CFLAGS)

clean:
	rm -rvf build
