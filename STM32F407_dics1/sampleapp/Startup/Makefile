CC 		= arm-none-eabi-gcc 
ASMFLAGS	=  -mcpu=cortex-m4 -g3 -c -x assembler-with-cpp --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o $@ $<

SRCS +=	\
	startup_stm32f407vgtx.s
OBJS = $(SRCS:.s=.o)

all : $(OBJS)
	@mv *.o $(OBJ)/
.s.o:
	$(CC) $(ASMFLAGS)

clean :
	rm -rf *.o 

