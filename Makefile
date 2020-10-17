all: bin/ex1

bin/ex1: obj/main.o obj/lists.o 
	mkdir bin
	g++ -Wall -Werror obj/main.o obj/lists.o  -o bin/ex1

obj/lists.o: src/lists.cpp 
	g++ -I include -Wall -Werror -c src/lists.cpp -o obj/lists.o 

obj/main.o: src/main.cpp
	mkdir obj
	g++ -I include -Wall -Werror -c src/main.cpp -o obj/main.o 

clean:
	rm -rf bin/ obj/

PHONY: all clean
