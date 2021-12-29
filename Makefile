CFLAGS 		= -Os -pipe -w
BUILD		= build
CC		= gcc

all: createDir coreutils
include core/make.config

clean:
	rm -rf $(BUILD) *~ */*~ */*/*~

createDir:
	@[ ! -d $(BUILD) ] && mkdir $(BUILD) || DIREXISTS=1
