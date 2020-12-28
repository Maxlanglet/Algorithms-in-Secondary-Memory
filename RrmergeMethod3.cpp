#include "RrmergeMethod3.hpp"
#define BUFFER_SIZE 1

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)


RrmergeMethod3::RrmergeMethod3(){
}

RrmergeMethod3::~RrmergeMethod3(){}


void RrmergeMethod3::rrmerge1(string outputfile, int Br, int num, ... ){
	OutputStream1 outputstream1;
	outputstream1.create(outputfile);
	
	int i;
	va_list valist;
	va_start(valist, num); //initialize valist for num number of arguments

	InputStream3* list = (InputStream3*)malloc(sizeof(InputStream3)*num);//////:::change to 4
	//Creating a list containing the Input Streams associated to the files
	for (i=0 ; i < num; i++) { 
		string j=va_arg(valist, const char *);
		InputStream3 in ;
		in.open(j);
		list[i]=in;	
	}
	va_end(valist); //Cleaning memory reserved for valist
	while(num!=0){//Reading in a round-robin way until all files are processed
		label:
		for(int i=0;i<num;i++){
			string s = list[i].readln(Br);//default value
			if(s.size()!=0){
				outputstream1.writeln(s);
			}else{
				num--;
				list[i].close();
				for (int j = i; j < num; j++) { 
					list[j] = list[j+1];
				}
			}if(s.size() ==0 && i!=num-1){
				goto label;
			}
		}
	}
	outputstream1.close();
	free(list);
}

void RrmergeMethod3::rrmerge2(string outputfile, int Br, int num, ... ){
	OutputStream2 outputstream2;
	outputstream2.create(outputfile.c_str());
	
	int i;
	va_list valist;
	va_start(valist, num); //initialize valist for num number of arguments

	InputStream3* list = (InputStream3*)malloc(sizeof(InputStream3)*num);//////:::change to 4
	//Creating a list containing the Input Streams associated to the files
	for (i=0 ; i < num; i++) { 
		string j=va_arg(valist, const char *);
		InputStream3 in ;
		in.open(j);
		list[i]=in;	
	}
	va_end(valist); //Cleaning memory reserved for valist
	while(num!=0){//Reading in a round-robin way until all files are processed
		label:
		for(int i=0;i<num;i++){
			string s = list[i].readln(Br);
			if(s.size()!=0){
				outputstream2.writeln(s);
			}else{
				num--;
				list[i].close();
				for (int j = i; j < num; j++) { 
					list[j] = list[j+1];
				}
			}if(s.size() ==0 && i!=num-1){
				goto label;
			}
		}
	}
	outputstream2.close();
	free(list);
}

void RrmergeMethod3::rrmerge3(string outputfile, int Br, int Bw, int num, ... ){
	OutputStream3 outputstream3;
	outputstream3.create(outputfile);
	
	int i;
	va_list valist;
	va_start(valist, num); //initialize valist for num number of arguments

	InputStream3* list = (InputStream3*)malloc(sizeof(InputStream3)*num);//////:::change to 4
	//Creating a list containing the Input Streams associated to the files
	for (i=0 ; i < num; i++) { 
		string j=va_arg(valist, const char *);
		InputStream3 in ;/////change to 4
		in.open(j);
		list[i]=in;	
	}
	va_end(valist); //Cleaning memory reserved for valist
	while(num!=0){//Reading in a round-robin way until all files are processed
		label:
		for(int i=0;i<num;i++){
			string s = list[i].readln(Br);
			if(s.size()!=0){
				outputstream3.writeln(s, Bw);
			}else{
				num--;
				list[i].close();
				for (int j = i; j < num; j++) { 
					list[j] = list[j+1];
				}
			}if(s.size() ==0 && i!=num-1){
				goto label;
			}
		}
	}
	outputstream3.close();
	free(list);
}

void RrmergeMethod3::rrmerge4(string outputfile, int Br, int Bw, int num, ... ){
	OutputStream4 outputstream4;
	outputstream4.create(outputfile);
	
	int i;
	va_list valist;
	va_start(valist, num); //initialize valist for num number of arguments

	InputStream3* list = (InputStream3*)malloc(sizeof(InputStream3)*num);//////:::change to 4
	//Creating a list containing the Input Streams associated to the files
	for (i=0 ; i < num; i++) { 
		string j=va_arg(valist, const char *);
		InputStream3 in ;/////change to 4
		in.open(j);
		list[i]=in;	
	}
	va_end(valist); //Cleaning memory reserved for valist
	while(num!=0){//Reading in a round-robin way until all files are processed
		label:
		for(int i=0;i<num;i++){
			string s = list[i].readln(Br);
			if(s.size()!=0){
				outputstream4.writeln(s, Bw);
			}else{
				num--;
				list[i].close();
				for (int j = i; j < num; j++) { 
					list[j] = list[j+1];
				}
			}if(s.size() ==0 && i!=num-1){
				goto label;
			}
		}
	}
	outputstream4.close2();
	free(list);
}



