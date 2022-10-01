CC = arm-linux-gnueabihf-gcc
LD = arm-linux-gnueabihf-ld
OBJCOPY = arm-linux-gnueabihf-objcopy

all : start.o
	$(LD) -Tgboot.lds -o gboot.elf $^
	$(OBJCOPY) -O binary gboot.elf gboot.bin

%.o : %.S
	$(CC) -g -c $^
%.o : %.c
	$(CC) -g -c $^


clean:
	rm -rf gboot.elf gboot.bin *.o

