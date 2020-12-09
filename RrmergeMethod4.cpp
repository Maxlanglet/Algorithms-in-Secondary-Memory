#include "RrmergeMethod4.hpp"
#define BUFFER_SIZE 1

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)


RrmergeMethod4::RrmergeMethod4(){
	InputStream4 instream4 = InputStream4();
}

RrmergeMethod4::~RrmergeMethod4(){}


void RrmergeMethod4::rrmerge1(string outputfile, int num, ... ){
	OutputStream1 outputstream1;
	outputstream1.create(outputfile);
	va_list valist;
	int i;
	va_start(valist, num); //initialize valist for num number of arguments
	for (i = 0; i < num; i++) { //access all the arguments assigned to valist
		va_arg(valist, int);
	}
	va_end(valist); //clean memory reserved for valist
}

void RrmergeMethod4::rrmerge2(string outputfile, int num, ... ){
	OutputStream2 outputstream2;
	outputstream2.create();
}

void RrmergeMethod4::rrmerge3(string outputfile, int num, ... ){
	OutputStream3 outputstream3;
	outputstream3.create();
}

void RrmergeMethod4::rrmerge4(string outputfile, int num, ... ){
	OutputStream4 outputstream4 = OutputStream4(outputfile);
	outputstream4.create();
}



