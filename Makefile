all: main clean

main: main.o InputStream1.o OutputStream1.o Timer.o InputStream2.o InputStream3.o InputStream4.o OutputStream2.o OutputStream3.o OutputStream4.o RrmergeMethod4.o  RrmergeMethod2.o
	g++ -O3 -std=c++11 main.o OutputStream1.o InputStream1.o InputStream2.o InputStream3.o InputStream4.o OutputStream2.o OutputStream3.o OutputStream4.o RrmergeMethod4.o  RrmergeMethod2.o Timer.o -o main

OutputStream1.o: OutputStream1.cpp OutputStream1.hpp
	g++ -O3 -std=c++11 -c OutputStream1.cpp

OutputStream2.o: OutputStream2.cpp OutputStream2.hpp
	g++ -O3 -std=c++11 -c OutputStream2.cpp

OutputStream3.o: OutputStream3.cpp OutputStream3.hpp
	g++ -O3 -std=c++11 -c OutputStream3.cpp

OutputStream4.o: OutputStream4.cpp OutputStream4.hpp
	g++ -O3 -std=c++11 -c OutputStream4.cpp

InputStream1.o: InputStream1.cpp InputStream1.hpp
	g++ -O3 -std=c++11 -c InputStream1.cpp

InputStream2.o: InputStream2.cpp InputStream2.hpp
	g++ -O3 -std=c++11 -c InputStream2.cpp

InputStream3.o: InputStream3.cpp InputStream3.hpp
	g++ -O3 -std=c++11 -c InputStream3.cpp

InputStream4.o: InputStream4.cpp InputStream4.hpp
	g++ -O3 -std=c++11 -c InputStream4.cpp

RrmergeMethod4.o: RrmergeMethod4.cpp RrmergeMethod4.hpp
	g++ -O3 -std=c++11 -c RrmergeMethod4.cpp

RrmergeMethod2.o: RrmergeMethod2.cpp RrmergeMethod2.hpp
	g++ -O3 -std=c++11 -c RrmergeMethod2.cpp

Timer.o: Timer.cpp Timer.hpp
	g++ -O3 -std=c++11 -c Timer.cpp

clean:
	rm -f *.o