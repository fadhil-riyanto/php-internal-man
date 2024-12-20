CFLAGS = -g

phpman: phpman.o dbref.o log.o docs_func.o docs_macro.o
	gcc phpman.o dbref.o log.o docs_func.o docs_macro.o -o phpman ${CFLAGS}

phpman.o: phpman.c
	gcc phpman.c -o phpman.o -c $(CFLAGS)

dbref.o: dbref.c
	gcc dbref.c -o dbref.o -c $(CFLAGS)

log.o: modules/log.c-patched/src/log.c
	gcc modules/log.c-patched/src/log.c -o log.o -c $(CFLAGS)

# docs related
docs_func.o: ./docs/func.c 
	gcc ./docs/func.c -o docs_func.o -c $(CFLAGS)

docs_macro.o: ./docs/macro.c 
	gcc ./docs/macro.c -o docs_macro.o -c $(CFLAGS)

clean:
	rm phpman.o 
	rm dbref.o 
	rm log.o
	rm docs_func.o
	rm docs_macro.o
	rm phpman

install: 
	sudo cp ./phpman /usr/bin/phpman

uninst:
	sudo rm /usr/bin/phpman