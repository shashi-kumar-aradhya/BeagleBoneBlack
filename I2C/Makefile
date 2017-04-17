CHAIN=arm-none-eabi
CFLAGS=-std=gnu99 -g -Wall -mfpu=neon -mhard-float -mcpu=cortex-a8
AFLAGS=-mfpu=neon
OBJ=obj/
BIN=bin/
SRC=src/
LIB_PATH=./../minimul_c_lib/
INC=-I./../minimul_c_lib/string/include/	\
    -I./../minimul_c_lib/misc/include/

all: test copy

test : dir $(LIB_PATH)$(OBJ)*.o start.o1 control_module.o clock.o uart_console.o main.o GPIO.o div.o
	$(CHAIN)-ld -T memmap.ld $(OBJ)start.o1 $(OBJ)*.o $(LIB_PATH)$(OBJ)*.o -o $(OBJ)main.elf
	$(CHAIN)-objcopy $(OBJ)main.elf $(BIN)spl.boot -O binary
	$(CHAIN)-objdump -DS $(OBJ)main.elf > $(BIN)startup.lst

dir :
	@mkdir -p $(OBJ) $(BIN)

$(LIB_PATH)$(OBJ)*.o :force_look 
	@echo "building string lib/"
	@cd $(LIB_PATH); $(MAKE)
start.o1: start.s
	$(CHAIN)-as $(AFLAGS) start.s -o $(OBJ)start.o1

main.o: main.c
	$(CHAIN)-gcc $(CFLAGS) $(INC) -c main.c -o $(OBJ)main.o

GPIO.o: GPIO.c
	$(CHAIN)-gcc $(CFLAGS) $(INC) -c GPIO.c -o $(OBJ)GPIO.o

pad.o: pad.c
	$(CHAIN)-gcc $(CFLAGS) $(INC) -c pad.c -o $(OBJ)pad.o

control_module.o: control_module.c
	$(CHAIN)-gcc $(CFLAGS) $(INC) -c control_module.c -o $(OBJ)control_module.o

clock.o: clock.c
	$(CHAIN)-gcc $(CFLAGS) $(INC) -c clock.c -o $(OBJ)clock.o

LED.o: LED.c
	$(CHAIN)-gcc $(CFLAGS) $(INC) -c LED.c -o $(OBJ)LED.o

uart_console.o:uart_console.c
	$(CHAIN)-gcc $(CFLAGS) $(INC) -c uart_console.c -o $(OBJ)uart_console.o
div.o: div.c
	$(CHAIN)-gcc $(CFLAGS) $(INC) -c div.c -o $(OBJ)div.o

copy:
	@cp -v $(BIN)spl.boot /tftpboot/download.bin 

force_look:
	@true


clean:
	@cd $(LIB_PATH); $(MAKE) clean
	@rm -rf $(OBJ)*.o
	@rm -rf $(OBJ)*.objstart
	@rm -rf $(OBJ)*.elf
	@rm -rf $(BIN)*.boot
	@rm -rf ../boot/*.boot
	@rm -rf $(OBJ)
	@rm -rf $(BIN)
	@rm -rf $(LIB_PATH)$(BIN)*
	@rm -rf $(LIB_PATH)$(OBJ)*

cscope :
	@cscope -R

dump:
	$(CHAIN)-objdump -D $(OBJ)main.elf
