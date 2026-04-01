CC = $(CROSS_COMPILE)gcc

all: writer

writer:
	$(CC) -g -Wall -c -o writer.o writer.c
	$(CC) -g -Wall  writer.o -o writer

clean:
	rm -f *.o writer *.elf *.map
