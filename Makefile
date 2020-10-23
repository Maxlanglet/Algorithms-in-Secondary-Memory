all: main clean

main: main.o Stream.o Timer.o
	g++ -O3 -std=c++11 main.o Stream.o Timer.o -o main

Stream.o: Stream.cpp Stream.hpp
	g++ -O3 -std=c++11 -c Stream.cpp

Timer.o: Timer.cpp Timer.hpp
	g++ -O3 -std=c++11 -c Timer.cpp

clean:
	rm -f *.o