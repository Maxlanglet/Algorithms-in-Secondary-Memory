#include "RrmergeMethod4.hpp"
#define BUFFER_SIZE 1

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)


RrmergeMethod4::RrmergeMethod4(){
	//InputStream4 instream4 = InputStream4;
}

RrmergeMethod4::~RrmergeMethod4(){}


void RrmergeMethod4::rrmerge1(string outputfile, int num, ... ){
	OutputStream1 outputstream1;
	outputstream1.create(outputfile);
	
	int i;
	va_list valist;
	va_start(valist, num); //initialize valist for num number of arguments

	InputStream4* list = (InputStream4*)malloc(sizeof(InputStream4)*num);//////:::change to 4
	//Creating a list containing the Input Streams associated to the files
	for (i=0 ; i < num; i++) { 
		string j=va_arg(valist, const char *);
		InputStream4 in ;
		in.open(j.c_str());
		list[i]=in;	
	}
	va_end(valist); //Cleaning memory reserved for valist
	while(num!=0){//Reading in a round-robin way until all files are processed
		for(int i=0;i<num;i++){
			string s = list[i].readln(1);
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

void RrmergeMethod4::rrmerge2(string outputfile, int num, ... ){
	OutputStream2 outputstream2;
	outputstream2.create(outputfile.c_str());
	
	int i;
	va_list valist;
	va_start(valist, num); //initialize valist for num number of arguments

	InputStream4* list = (InputStream4*)malloc(sizeof(InputStream4)*num);//////:::change to 4
	//Creating a list containing the Input Streams associated to the files
	for (i=0 ; i < num; i++) { 
		string j=va_arg(valist, const char *);
		InputStream4 in ;
		in.open(j.c_str());
		list[i]=in;	
	}
	va_end(valist); //Cleaning memory reserved for valist
	while(num!=0){//Reading in a round-robin way until all files are processed
		for(int i=0;i<num;i++){
			string s = list[i].readln(1);
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

void RrmergeMethod4::rrmerge3(string outputfile, int num, ... ){
	OutputStream3 outputstream3;
	outputstream3.create(outputfile);
	
	int i;
	va_list valist;
	va_start(valist, num); //initialize valist for num number of arguments

	InputStream4* list = (InputStream4*)malloc(sizeof(InputStream4)*num);//////:::change to 4
	//Creating a list containing the Input Streams associated to the files
	for (i=0 ; i < num; i++) { 
		string j=va_arg(valist, const char *);
		InputStream4 in ;/////change to 4
		in.open(j.c_str());
		list[i]=in;	
	}
	va_end(valist); //Cleaning memory reserved for valist
	while(num!=0){//Reading in a round-robin way until all files are processed
		for(int i=0;i<num;i++){
			string s = list[i].readln(1);
			if(s.size()!=0){
				outputstream3.writeln(s);
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

void RrmergeMethod4::rrmerge4(string outputfile, int num, ... ){
	OutputStream4 outputstream4;
	outputstream4.create(outputfile);
	
	int i;
	va_list valist;
	va_start(valist, num); //initialize valist for num number of arguments

	InputStream4* list = (InputStream4*)malloc(sizeof(InputStream4)*num);//////:::change to 4
	//Creating a list containing the Input Streams associated to the files
	for (i=0 ; i < num; i++) { 
		string j=va_arg(valist, const char *);
		InputStream4 in ;/////change to 4
		in.open(j.c_str());
		list[i]=in;	
	}
	va_end(valist); //Cleaning memory reserved for valist
	while(num!=0){//Reading in a round-robin way until all files are processed
		for(int i=0;i<num;i++){
			string s = list[i].readln(1);
			if(s.size()!=0){
				outputstream4.writeln(s);
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


