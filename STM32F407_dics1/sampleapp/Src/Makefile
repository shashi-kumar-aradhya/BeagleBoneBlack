CFLAGS          = -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(basename $<).d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o $@
CC		= arm-none-eabi-gcc
SRCS            += \
main.c              \
syscalls.c          \
sysmem.c

OBJS = $(SRCS:.c=.o)

all : $(OBJS)
	@mv *.o *.d *.su $(OBJ)/
.c.o:
	$(CC) $< $(CFLAGS)

clean :
	rm -rf *.d *.o *.su
