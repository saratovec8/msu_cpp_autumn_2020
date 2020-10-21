CC = g++ --std=c++17

all: prog 

pr: test.o parser.o 
	$(CC) test.o parser.o -o prog

parser.o: parser.cpp
	$(CC) -c parser.cpp

test.o: test.cpp
	$(CC) -c test.cpp

test: prog
	./prog

clean:
	rm *.o prog
