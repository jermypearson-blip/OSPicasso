CC = gcc
AS = nasm
LD = ld
QEMU = qemu-system-i386

CFLAGS = -m32 -ffreestanding -fno-stack-protector -Wall -Wextra -c
ASFLAGS = -f elf32
LDFLAGS = -m elf_i386 -T linker.ld

C_SOURCES = $(wildcard *.c)
OBJS = boot.o $(C_SOURCES:.c=.o)
TARGET = kernel.bin

all: $(TARGET)

boot.o: boot.s
	$(AS) $(ASFLAGS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(TARGET): $(OBJS) linker.ld
	$(LD) $(LDFLAGS) -o $@ $(OBJS)

run: $(TARGET)
	$(QEMU) -kernel $(TARGET)

clean:
	rm -f *.o $(TARGET)