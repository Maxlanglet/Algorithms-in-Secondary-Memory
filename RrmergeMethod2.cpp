#include "RrmergeMethod2.hpp"
#define BUFFER_SIZE 1

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)


RrmergeMethod2::RrmergeMethod2(){
	
}

RrmergeMethod2::~RrmergeMethod2(){}


void RrmergeMethod2::rrmerge1(string outputfile, int num, ... ){
	OutputStream1 outputstream1;
	outputstream1.create(outputfile);
	
	int i;
	va_list valist;
	va_start(valist, num); //initialize valist for num number of arguments

	InputStream2* list = (InputStream2*)malloc(sizeof(InputStream2)*num);//////:::change to 4
	//Creating a list containing the Input Streams associated to the files
	for (i=0 ; i < num; i++) { 
		string j=va_arg(valist, const char *);
		InputStream2 in ;
		in.open(j.c_str());
		list[i]=in;	
	}
	va_end(valist); //Cleaning memory reserved for valist
	while(num!=0){//Reading in a round-robin way until all files are processed
		for(int i=0;i<num;i++){
			string s = list[i].readln();
			if(s.size()!=0){
				outputstream1.writeln(s);
			}else{
				num--;
				for (int j = i; j < num; j++) { 
					list[j] = list[j+1];
				}
			}
		}
	}
	free(list);
}

void RrmergeMethod2::rrmerge2(string outputfile, int num, ... ){
	OutputStream2 outputstream2;
	outputstream2.create(outputfile.c_str());
	
	int i;
	va_list valist;
	va_start(valist, num); //initialize valist for num number of arguments

	InputStream2* list = (InputStream2*)malloc(sizeof(InputStream2)*num);//////:::change to 4
	//Creating a list containing the Input Streams associated to the files
	for (i=0 ; i < num; i++) { 
		string j=va_arg(valist, const char *);
		InputStream2 in ;
		in.open(j.c_str());
		list[i]=in;	
	}
	va_end(valist); //Cleaning memory reserved for valist
	while(num!=0){//Reading in a round-robin way until all files are processed
		for(int i=0;i<num;i++){
			string s = list[i].readln();
			if(s.size()!=0){
				outputstream2.writeln(s);
			}else{
				num--;
				for (int j = i; j < num; j++) { 
					list[j] = list[j+1];
				}
			}
		}
	}
	free(list);
}

void RrmergeMethod2::rrmerge3(string outputfile, int B, int num, ... ){
	OutputStream3 outputstream3;
	outputstream3.create(outputfile);
	
	int i;
	va_list valist;
	va_start(valist, num); //initialize valist for num number of arguments

	InputStream2* list = (InputStream2*)malloc(sizeof(InputStream2)*num);//////:::change to 4
	//Creating a list containing the Input Streams associated to the files
	for (i=0 ; i < num; i++) { 
		string j=va_arg(valist, const char *);
		InputStream2 in ;/////change to 4
		in.open(j.c_str());
		list[i]=in;	
	}
	va_end(valist); //Cleaning memory reserved for valist
	while(num!=0){//Reading in a round-robin way until all files are processed
		for(int i=0;i<num;i++){
			string s = list[i].readln();
			if(s.size()!=0){
				outputstream3.writeln(s, B);
			}else{
				num--;
				for (int j = i; j < num; j++) { 
					list[j] = list[j+1];
				}
			}
		}
	}
	free(list);
}

void RrmergeMethod2::rrmerge4(string outputfile, int B, int num, ... ){
	OutputStream4 outputstream4;
	outputstream4.create(outputfile);
	
	int i;
	va_list valist;
	va_start(valist, num); //initialize valist for num number of arguments

	InputStream2* list = (InputStream2*)malloc(sizeof(InputStream2)*num);//////:::change to 4
	//Creating a list containing the Input Streams associated to the files
	for (i=0 ; i < num; i++) { 
		string j=va_arg(valist, const char *);
		InputStream2 in ;/////change to 4
		in.open(j.c_str());
		list[i]=in;	
	}
	va_end(valist); //Cleaning memory reserved for valist
	while(num!=0){//Reading in a round-robin way until all files are processed
		for(int i=0;i<num;i++){
			string s = list[i].readln();
			if(s.size()!=0){
				outputstream4.writeln(s,B);
			}else{
				num--;
				for (int j = i; j < num; j++) { 
					list[j] = list[j+1];
				}
			}
		}
	}
	free(list);
}
