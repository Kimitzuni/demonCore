CFLAGS 		= -Os -pipe -w
BUILD		= build
CC		= gcc

all: info createDir userview bsh fileout no

info:
	@echo ""
	@echo "Build Directory:  $(BUILD)/"
	@echo "CFLAGS:           $(CFLAGS)"
	@echo "Compiler:         $(CC)"
	@echo "---------------------------------"
	@sleep 0.25

createDir:
	@[ ! -d $(BUILD) ] && mkdir $(BUILD) || DIREXISTS=1

userview:
	@echo "Building 'userview'"
	@$(CC) core/userview/userview.c -o $(BUILD)/userview $(CFLAGS)
	@sleep 0.25

bsh:
	@echo "Building 'bsh'"
	@$(CC) core/bsh/bsh_main.c -o $(BUILD)/bsh $(CFLAGS)
	@sleep 0.25

fileout:
	@echo "Building 'fileout'"
	@$(CC) core/fileout/fileout.c -o $(BUILD)/fileout $(CFLAGS)
	@sleep 0.25

no:
	@echo "Building 'no'"
	@$(CC) core/no/no.c -o $(BUILD)/no $(CFLAGS)
	@sleep 0.25

clean:
	rm -rvf $(BUILD)
