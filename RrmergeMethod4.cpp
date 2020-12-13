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

	InputStream2* list = (InputStream2*)malloc(sizeof(InputStream2)*num);//////:::change to 4


	for (i=0 ; i < num; i++) { //access all the arguments assigned to valist
		string j=va_arg(valist, const char *);
		InputStream2 in ;/////change to 4
		in.open(j.c_str());
		list[i]=in;
		cout<<"entry:"<<j<<endl;
		printf("\n");	
	}
	va_end(valist); //clean memory reserved for valist
	while(num!=0){
		cout<<"dans le while"<<endl;
		for(int i=0;i<num;i++){
			string s = list[i].readln();
			cout<<s<<endl;
			if(s.size()!=0){
				outputstream1.writeln(s);
			}else{
				cout<<"un fichier fini ! "<<endl;
				num--;
				for (int j = i; j < num; j++) { 
					list[j] = list[j+1];
				}
			}
		}
	}
}

void RrmergeMethod4::rrmerge2(string outputfile, int num, ... ){
	/*OutputStream2 outputstream2;
	outputstream2.create();*/
}

void RrmergeMethod4::rrmerge3(string outputfile, int num, ... ){
	//OutputStream3 outputstream3;
	//outputstream3.create();
}

void RrmergeMethod4::rrmerge4(string outputfile, int num, ... ){
	//OutputStream4 outputstream4 = OutputStream4(outputfile);
	//outputstream4.create();
}



