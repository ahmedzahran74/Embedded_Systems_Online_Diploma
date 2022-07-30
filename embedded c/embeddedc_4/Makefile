CC=arm-none-eabi-
CFLAGS= -mtune=cortex-m4 -gdwarf-2 -g
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
Project_name=unit3_lab4_cortexM4

all: $(Project_name).bin


%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

$(Project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linkerscript.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map
	cp $(Project_name).elf $(Project_name).axf


$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	

clean_all:
	rm *.o *.elf *.bin

clean:
	rm *.elf *.bin