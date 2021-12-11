CFLAGS = -Os -pipe -w

all: createDir userview bsh fileout

createDir:
	@[ ! -d build ] && mkdir build || DIREXISTS=1

userview:
	@echo "Building 'userview'"
	@gcc core/userview/userview.c -o build/userview $(CFLAGS)
	@sleep 0.25

bsh:
	@echo "Building 'bsh'"
	@gcc core/bsh/bsh_main.c -o build/bsh $(CFLAGS)
	@sleep 0.25

fileout:
	@echo "Building 'fileout'"
	@gcc core/fileout/fileout.c -o build/fileout $(CFLAGS)
	@sleep 0.25

clean:
	rm -rvf build
