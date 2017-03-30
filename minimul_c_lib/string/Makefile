INC=./include/
SRC=./src/
OBJ=./obj/
BIN=./bin/


all : $(INC)string.h $(SRC)string.c main.c
	gcc -g -Wall -std=c99 -ffreestanding -nostdinc  -c -I$(INC) $(SRC)string.c -o $(OBJ)string.o

main :
	gcc -g -Wall -std=c99 -ffreestanding -nostdinc  -c -I$(INC) main.c -o $(OBJ)main.o
	gcc -g -Wall -std=c99 -ffreestanding -nostdinc $(OBJ)main.o $(OBJ)string.o -o $(BIN)exe


clean :
	rm -rf $(OBJ)*.o $(BIN)exe
	rm -rf $(SRC).*.swp 
	rm -rf $(INC).*.swp 

gdb :
	gdb ./$(BIN)exe
