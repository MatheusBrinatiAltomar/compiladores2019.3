all: main

main: main.o
	g++ -o main *.o

main.o: main.cpp
	g++ -c *.cpp
clean: 
	rm -rf *.o main