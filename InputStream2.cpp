#include "InputStream2.hpp"
#define BUFFER_SIZE 1000

InputStream2::InputStream2(){
	offset=0;
}

InputStream2::~InputStream2(){}


void InputStream2::open(const char* path){
	// Opens the file in reading mode
	file = fopen (path , "r");
	if (file == NULL) perror ("Error opening file");
}



/*Implementation of the readln method that reads a maximum of 1000 characters and puts them in a buffer of the same size
with the fgets system call
Returns the string of the read line or an empty string if the end of file has been reached
*/
string InputStream2::readln(){ 
	//Initializes a buffer of fixed size BUFFER_SIZE=1000
	char buffer [BUFFER_SIZE];
	string str="";
	int idx = 0;
	int i =0;
	// if we are not at the end of the file, we read the size of the buffer
	 if ( ! feof (file) ){    
		 //fgets stops when either the newline character has been met or when reading the whole 1000 characters whatever happens first
		if ( fgets (buffer , BUFFER_SIZE , file) != NULL ){
			//Look inside the buffer for the end of the line 
			while (idx < BUFFER_SIZE-1 && buffer[i] != '\n' && buffer[i] != '\r') str+=buffer[i], i++, idx++;
			str+="\n";
			return str;
		}else{
			return "";
		}
     }
}


/*Change the position pointer place in the file*/
void InputStream2::seek(int pos){
	fseek(file,pos,SEEK_SET);
}

/*Sequential reading 
Reads the entire file sequentially by calling readln until the line size is equal to 0
Returns the length of everything read
*/
int InputStream2::length(){
	int sum = 0 ;
	int line_size = 1;
	seek(0);
	 while (line_size > 0 ){
		line_size = readln().size();
		sum += line_size ;
	 }
	 return sum ;
}

/*Returns true if the end of the file is reached*/
bool InputStream2::end_of_stream(){
	if(feof(file)){
		return true;
	}
	else{
		return false;
	}
}

/*Closes the file associated to the stream*/
void InputStream2::close(){
	fclose (file);
}


/*Reads through the file randomly
j is the number of randomized jumps
*/
int InputStream2::randjump(string filename, int j){
	int sum=0;
	int k=0;

	open(filename.c_str());

	//sz is the size of the file
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
