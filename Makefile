memgrind: mymalloc.o memgrind.o
		gcc -Wall $^ -o $@
%.o: %.c
		gcc -c -Wall $<
mymalloc.c: mymalloc.h
memgrind.c: mymalloc.h