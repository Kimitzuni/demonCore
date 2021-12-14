CFLAGS 		= -Os -pipe -w
BUILD		= build
CC		= gcc

all: info createDir userview bsh fileout no cwd truefalse proc \
	out

clean:
	rm -rvf $(BUILD)

info:
	@echo ""
	@echo "BUILD     $(BUILD)/"
	@echo "CFLAGS    $(CFLAGS)"
	@echo "CC        $(CC)"
	@echo "---------------------------------"
	@sleep 0.25

createDir:
	@[ ! -d $(BUILD) ] && mkdir $(BUILD) || DIREXISTS=1

userview:
	@echo " CC      userview"
	@$(CC) core/userview/userview.c -o $(BUILD)/userview $(CFLAGS)

bsh:
	@echo " CC      bsh"
	@$(CC) core/bsh/bsh_main.c -o $(BUILD)/bsh $(CFLAGS)

fileout:
	@echo " CC      fileout"
	@$(CC) core/fileout/fileout.c -o $(BUILD)/fileout $(CFLAGS)

no:
	@echo " CC      no"
	@$(CC) core/no/no.c -o $(BUILD)/no $(CFLAGS)

cwd:
	@echo " CC      cwd"
	@$(CC) core/cwd/cwd.c -o $(BUILD)/cwd $(CFLAGS)

proc:
	@echo " CC      proc"
	@$(CC) core/proc/proc.c -o $(BUILD)/proc $(CFLAGS)

truefalse:
	@echo " CC      true"
	@$(CC) core/truefalse/true.c -o $(BUILD)/true $(CFLAGS)
	@echo " CC      false"
	@$(CC) core/truefalse/false.c -o $(BUILD)/false $(CFLAGS)

out:
	@echo " CC      out"
	@$(CC) core/out/out.c -o $(BUILD)/out $(CFLAGS)

