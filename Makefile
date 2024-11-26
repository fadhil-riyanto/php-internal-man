CFLAGS = -ggdb3 -O0

phpman: phpman.o dbref.o 
	gcc phpman.o dbref.o -o phpman

phpman.o: phpman.c
	gcc phpman.c -o phpman.o -c $(CFLAGc)

dbref.o: dbref.c
	gcc dbref.c -o dbref.o -c $(CFLAGS)

clean:
	rm phpman.o
	rm phpman 
	rm dbref.o 
