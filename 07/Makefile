CC = --std=c++17

prog: main.o vector.o
	g++ main.o -o prog $(CC)
main.o: main.cpp
	g++ -c main.cpp $(CC)
vector.o: vector.h
	g++ -c vector.h $(CC)
clean:
	rm *.o
test:
	./prog
