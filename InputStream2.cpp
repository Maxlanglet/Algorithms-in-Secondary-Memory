#include "InputStream2.hpp"
#define BUFFER_SIZE 1000

InputStream2::InputStream2(){
	offset=0;
}

InputStream2::~InputStream2(){}


void InputStream2::open(const char* path){
	// open the file
	file = fopen (path , "r");
	if (file == NULL) perror ("Error opening file");
}



//reads in a buffer
string InputStream2::readln(){ //returns length of file read
	// initialize a buffer of fixed size BUFFER_SIZE
	char buffer [BUFFER_SIZE];
	string str="";
	int idx = 0;
	int i =0;
	// if we are not at the end of the file, we read the size of the buffer
	 if ( ! feof (file) ){
       
		if ( fgets (buffer , BUFFER_SIZE , file) != NULL ){
			while (idx < BUFFER_SIZE-1 && buffer[i] != '\n' && buffer[i] != '\r') str+=buffer[i], i++, idx++;

			if ( buffer[i] == '\n' || buffer[i] == '\r'){
				str+="\n";
				offset += i+1;
				seek(offset);

				return str;
			}
			else{
				offset+=i;
				seek(offset);
				return str;
			}

		}
		else{
			return "";
		}
     }
}



void InputStream2::seek(int pos){
	fseek(file,pos,SEEK_SET);
}

int InputStream2::length(string filename){
	open(filename.c_str());
	int sum = 0 ;
	int line_size = 1 ;
	//TODO: ajouter size of file juste pour etre sur, regarder autre length pour exemple
	 while (line_size > 0 ){
		line_size = readln().size();
		sum += line_size ;
	 }
	 return sum ;
}

bool InputStream2::end_of_stream(){
	if(feof(file)){
		return true;
	}
	else{
		return false;
	}
}

void InputStream2::close(){
	fclose (file);
}


int InputStream2::randjump(string filename, int j){//seems to work fine
	int sum=0;
	//number of lines read
	int k=0;

	open(filename.c_str());

	//sz is the length of the file
	fseek(file, 0L, SEEK_END);
	int sz = ftell(file);
	fseek(file, 0L, SEEK_SET);
	srand ( 2 ); //for true random else seeded
	int pos = rand();

	while (k<j){
		srand ( pos );
		pos = 0 + (rand() % static_cast<int>(sz - 0 + 1));
		seek(pos);
		int line_size = readln().size();
		sum+=line_size;
		k++;
	}

	return sum;
}
