CHAIN=arm-linux-gnueabi
CFLAGS=-std=gnu99 -g -Wall -mfpu=neon -mhard-float -mcpu=cortex-a8
AFLAGS=-mfpu=neon
OBJ=obj/
BIN=bin/
LIB_PATH=./../minimul_c_lib/string/obj/


all: test copy

test : dir start.o1 control_module.o clock.o uart_console.o main.o GPIO.o
	$(CHAIN)-ld -T memmap.ld $(OBJ)start.o1 $(OBJ)*.o $(LIB_PATH)string.o -o $(OBJ)main.elf
	$(CHAIN)-objcopy $(OBJ)main.elf $(BIN)spl.boot -O binary
	$(CHAIN)-objdump -DS $(OBJ)main.elf > $(BIN)startup.lst

dir :
	@mkdir -p $(OBJ) $(BIN)
start.o1: start.s
	$(CHAIN)-as $(AFLAGS) start.s -o $(OBJ)start.o1

main.o: main.c
	$(CHAIN)-gcc $(CFLAGS) -c main.c -o $(OBJ)main.o

GPIO.o: GPIO.c
	$(CHAIN)-gcc $(CFLAGS) -c GPIO.c -o $(OBJ)GPIO.o

pad.o: pad.c
	$(CHAIN)-gcc $(CFLAGS) -c pad.c -o $(OBJ)pad.o

control_module.o: control_module.c
	$(CHAIN)-gcc $(CFLAGS) -c control_module.c -o $(OBJ)control_module.o

clock.o: clock.c
	$(CHAIN)-gcc $(CFLAGS) -c clock.c -o $(OBJ)clock.o

LED.o: LED.c
	$(CHAIN)-gcc $(CFLAGS) -c LED.c -o $(OBJ)LED.o

uart_console.o:uart_console.c
	$(CHAIN)-gcc $(CFLAGS) -c uart_console.c -o $(OBJ)uart_console.o

copy:
	@cp -v $(BIN)spl.boot /tftpboot/download.bin 

clean:
	@rm -rf $(OBJ)*.o
	@rm -rf $(OBJ)*.objstart
	@rm -rf $(OBJ)*.elf
	@rm -rf $(BIN)*.boot
	@rm -rf ../boot/*.boot
	@rm -rf $(OBJ)
	@rm -rf $(BIN)

cscope :
	@cscope -R

dump:
	$(CHAIN)-objdump -D $(OBJ)main.elf
