CFLAGS = -g

phpman: phpman.o dbref.o log.o
	gcc phpman.o dbref.o log.o -o phpman ${CFLAGS}

phpman.o: phpman.c
	gcc phpman.c -o phpman.o -c $(CFLAGS)

dbref.o: dbref.c
	gcc dbref.c -o dbref.o -c $(CFLAGS)

log.o: modules/log.c-patched/src/log.c
	gcc modules/log.c-patched/src/log.c -o log.o -c $(CFLAGS)

clean:
	rm phpman.o
	rm phpman 
	rm dbref.o 
	rm log.o

install: 
	sudo cp ./phpman /usr/bin/phpman

uninst:
	sudo rm /usr/bin/phpman