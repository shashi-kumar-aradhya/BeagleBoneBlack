OBJ=obj/
PARENTOBJ = ../obj/
CHAIN=arm-none-eabi-

all : dir $(OBJ)GPIO.o $(OBJ)EEPROM.o
	$(CHAIN)ld -r $(OBJ)*.o -o $(PARENTOBJ)board.o

dir :
	@mkdir -p $(OBJ)

$(OBJ)GPIO.o : GPIO.c
	$(CHAIN)gcc $(CFLAGS) -c GPIO.c -o $(OBJ)GPIO.o

$(OBJ)EEPROM.o : EEPROM.c
	$(CHAIN)gcc $(CFLAGS) -c EEPROM.c -o $(OBJ)EEPROM.o

$(OBJ)I2C.o : I2C.c
	$(CHAIN)gcc $(CFLAGS) -c I2C.c -o $(OBJ)I2C.o
clean :
	rm -rf $(OBJ) 



