CHAIN=arm-none-eabi
CFLAGS=-std=gnu99 -g -Wall -mfpu=neon -mhard-float -mcpu=cortex-a8
INC=./include/
SRC=./src/
OBJ=./obj/
BIN=./bin/


all : dir $(INC)string.h $(SRC)string.c  
	@$(CHAIN)-gcc $(CFLAGS) -c -I$(INC) $(SRC)string.c -o $(OBJ)string.o
	@$(CHAIN)-ar rc $(BIN)libutil.a $(OBJ)string.o

dir :
	@mkdir -p $(OBJ) $(BIN)
main :
	gcc -g -Wall -std=c99 -ffreestanding -nostdinc  -c -I$(INC) main.c -o $(OBJ)main.o
	gcc -g -Wall -std=c99 -ffreestanding -nostdinc $(OBJ)main.o -L. -lutil -o $(BIN)exe


clean :
	rm -rf $(OBJ)*.o $(BIN)*.o
	rm -rf $(SRC).*.swp 
	rm -rf $(INC).*.swp 

gdb :
	gdb ./$(BIN)exe
