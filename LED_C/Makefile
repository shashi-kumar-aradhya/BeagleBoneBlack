#CHAIN=arm-none-eabi
CHAIN=arm-linux-gnueabihf

all: start.s main.c
	$(CHAIN)-as start.s -o start.o
	$(CHAIN)-gcc -c main.c -o main.o
#	$(CHAIN)-ld start.o main.o -entry _start -o main.elf
	$(CHAIN)-ld start.o main.o -T memmap.ld -o main.elf
	$(CHAIN)-objcopy main.elf spl.boot -O binary
	$(CHAIN)-objdump -DS main.elf > asm.lst

   
copy:
	@cp spl.boot /tftpboot/download.bin

clean:
	rm -rf *.o *.lst
	rm -rf *.elf
	rm -rf *.boot
