CC = arm-linux-gnueabihf-gcc
LD = arm-linux-gnueabihf-ld
OBJCOPY = arm-linux-gnueabihf-objcopy
OBJDUMP = arm-linux-gnueabihf-objdump
OBJ_DIR = out

TARGET=uart

all : start.o main.o 
	$(LD) -T$(TARGET).lds -o $(TARGET).elf $^ 
	$(OBJCOPY) -O binary $(TARGET).elf $(TARGET).bin
	$(OBJDUMP) -D -m arm $(TARGET).elf > $(TARGET).dis

%.o : %.S
	$(CC) -g -c $< 
%.o : %.c
	$(CC) -g -c $< 


clean:
	rm -rf $(TARGET).elf $(TARGET).bin *.o *.dis

install:
	xfel write 0x20000 ./$(TARGET).bin;xfel exec 0x20000;