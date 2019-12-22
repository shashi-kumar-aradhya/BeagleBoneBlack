################################################################################
# Automatically-generated file. Do not edit!
################################################################################
BIN 		= Debug
NAME_BIN 	= $(notdir $(CURDIR))
PWD_NAME 	= $(CURDIR)
export OBJ 	= $(CURDIR)/$(BIN)/objs
CC       	= arm-none-eabi-gcc

ASMFLAGS	= $(OBJ)/*.o   -mcpu=cortex-m4 -T"$(PWD_NAME)/STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="$(NAME_BIN).map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group

INC		= ./Inc
# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
$(NAME_BIN).elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
$(NAME_BIN).list \



# All Target
all: dir $(NAME_BIN).elf secondary-outputs

dir:
	@mkdir -p $(BIN) 
	@mkdir -p $(OBJ)

# Tool invocations
$(NAME_BIN).elf: $(OBJS) $(USER_OBJS) $(PWD_NAME)/STM32F407VGTX_FLASH.ld
	@$(MAKE) --no-print-directory -C Startup/
	@$(MAKE) --no-print-directory -C Src/
	$(CC) -o "$(NAME_BIN).elf" $(ASMFLAGS)
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@mv *.list *.map *.elf $(BIN)
	@echo ' '

$(NAME_BIN).list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "$(NAME_BIN).list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
#	rm -rf Src/*.o Startup/*.o
	@$(MAKE) --no-print-directory -C Startup/ clean
	@$(MAKE) --no-print-directory -C Src/ clean
	rm -rf $(BIN)
	-@echo ' '
size :
	arm-none-eabi-size Debug/Src/syscalls.o

#secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)
secondary-outputs: $(OBJDUMP_LIST) $(SIZE_OUTPUT)

.PHONY: all clean dependents size
.SECONDARY:

-include ../makefile.targets
