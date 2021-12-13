CFLAGS 		= -Os -pipe -w
BUILD		= build

all: info createDir userview bsh fileout no

info:
	@echo ""
	@echo "demonCore Makefile"
	@echo ""
	@echo "Build Directory:  $(BUILD)/"
	@echo "CFLAGS:           $(CFLAGS)"

createDir:
	@[ ! -d $(BUILD) ] && mkdir $(BUILD) || DIREXISTS=1

userview:
	@echo "Building 'userview'"
	@gcc core/userview/userview.c -o $(BUILD)/userview $(CFLAGS)
	@sleep 0.25

bsh:
	@echo "Building 'bsh'"
	@gcc core/bsh/bsh_main.c -o $(BUILD)/bsh $(CFLAGS)
	@sleep 0.25

fileout:
	@echo "Building 'fileout'"
	@gcc core/fileout/fileout.c -o $(BUILD)/fileout $(CFLAGS)
	@sleep 0.25

no:
	@echo "Building 'no'"
	@gcc core/no/no.c -o $(BUILD)/no $(CFLAGS)
	@sleep 0.25

clean:
	rm -rvf $(BUILD)
