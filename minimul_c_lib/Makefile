HAIN=arm-none-eabi
CFLAGS=-std=gnu99 -g -Wall -mfpu=neon -mhard-float -mcpu=cortex-a8
AFLAGS=-mfpu=neon
OBJ=obj/
BIN=bin/
SRC=src/
MISC = ./misc/
STR = ./string/

all :	dir misc string

dir :
	@mkdir -p $(MISC)$(OBJ)
	@mkdir -p $(STR)$(OBJ)
	@mkdir -p $(OBJ)

misc :	force_look
	@echo "building misc lib/"
	        @cd $(MISC); $(MAKE)
		cp -rf $(MISC)$(OBJ)*.o $(OBJ)

string : force_look
	@echo "building string lib/"
	        @cd $(STR); $(MAKE)
		cp -rf $(STR)$(OBJ)*.o $(OBJ)

force_look:
	@true
clean :
	@echo "Clean is called from uart"
	@cd $(MISC); $(MAKE) clean
	@cd $(STR); $(MAKE) clean
	rm -rf $(OBJ)*
	
