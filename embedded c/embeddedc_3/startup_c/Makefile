cc=arm-none-eabi-
MACH=arm926ej-s
CFLAGS=-gdwarf-2 -mcpu=$(MACH)
INC=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ=$(SRC:.c=.o)
As=$(wildcard *.s)
AsOBJ=$(As:.s=.o) 
all:learn_in_depth.bin

%.o : %.c
	$(cc)gcc $(CFLAGS) $(INC) -c $< -o $@
	
%.o:%.s
	$(cc)as  $(CFLAGS) $< -o $@
	
learn_in_depth.elf: $(OBJ) $(AsOBJ)
	$(cc)ld -T linkerscript.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=map_file.map 
	
learn_in_depth.bin:learn_in_depth.elf
	$(cc)objcopy -O binary $< $@
	
clean:
		rm -rf *.o *~