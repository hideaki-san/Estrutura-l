all: libed myapps

libed:
	@gcc -c ./src/tree.c -I ./include -o ./obj/tree.o

myapps:
	@gcc ./app/tree_main.c ./obj/*.o -I ./include -o ./bin/app

run:
	@./bin/app.exe