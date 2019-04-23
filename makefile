.PHONY: clean
chessviz: build/main.o build/board_print.o build/board.o
	gcc -Wall -Werror build/main.o build/board_print.o build/board.o -o chessviz

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o

build/board_print.o: src/board_print.c
	gcc -Wall -Werror -c src/board_print.c -o build/board_print.o

build/board.o: src/board.c
	gcc -Wall -Werror -c src/board.c -o build/board.o

clean:
	rm -rf build/*.o chessviz