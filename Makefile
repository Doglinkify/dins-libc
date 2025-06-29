OBJS := stdio.o stdlib.o string.o
CFLAGS := -I./include -nostdinc -ffreestanding

all: libdins.a crt0.o init.o fini.o

clean:
	rm -f *.o *.a

libdins.a: $(OBJS)
	x86_64-dlos-ar rcs libdins.a $(OBJS)

crt0.o: crt0.s
	x86_64-dlos-as -o crt0.o crt0.s

init.o: init.s
	x86_64-dlos-as -o init.o init.s

fini.o: fini.s
	x86_64-dlos-as -o fini.o fini.s

stdio.o: stdio.c include/stdio.h
	x86_64-dlos-gcc $(CFLAGS) -c stdio.c -o stdio.o

stdlib.o: stdlib.c include/stdlib.h
	x86_64-dlos-gcc $(CFLAGS) -c stdlib.c -o stdlib.o

string.o: string.c include/string.h
	x86_64-dlos-gcc $(CFLAGS) -c string.c -o string.o
