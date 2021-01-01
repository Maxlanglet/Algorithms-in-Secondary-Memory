#include "InputStream1.hpp"
using namespace std;

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)

#define BUFFER_SIZE 20


InputStream1::InputStream1(){
	offset =0;
}

InputStream1::~InputStream1(){}

void InputStream1::open(string path){
	// opens the file
	filp = ::open(path.c_str(), O_RDONLY);	
}



/*Implementation of the readln method that reads a line character by character using the read system call
Returns an empty string if the end of file has been reached
*/
string InputStream1::readln(){  
	string line =""; //return value
	int bytes_read =1;
	if (filp){
		char* c = (char*) malloc(sizeof(char));
		while( bytes_read > 0){				
			bytes_read = read(filp, c, sizeof(char));	//Reads one character from file and puts it in buffer c
			line += c; 									//Appending the return string
			offset ++;
			if (*c == '\n' || *c == '\r'){				//Check if the end of the line has been reached and return the line if the case
				return line;
			}
		}
		free(c);
	}else{
		cout << "File is not open" << endl;}

	if (bytes_read ==0){
		return "";
	}
	else{
		return line;}
	
}
/*Change the position pointer place in the file*/
void InputStream1::seek(int pos){
	lseek (filp, pos, SEEK_SET);
}

/*Returns true if the end of the file is reached*/
bool InputStream1::end_of_stream(){
	int bytes_read = 1;

	if((bytes_read = lseek (filp, offset, SEEK_SET)) == -1){
		return true;
	}
	else{
		return false;
	}
}

/*Closes the file associated to the stream*/
void InputStream1::close(){
	::close(filp);
}

/*Sequential reading 
Reads the entire file sequentially by calling readln until the line size is equel to 0
Returns the length of everything read
*/
int InputStream1::length(string file){
	struct stat sb;
	seek(0);

	if (fstat(filp, &sb) == -1) 
	  handle_error("fstat");

	int line_size =1;
	int sum=0;
	while (line_size>0){
		line_size = readln().size();
		sum+=line_size;
	}
	return sum;
}

/*Reads through the file randomly
j is the number of randomized jumps
*/
int InputStream1::randjump(string file, int j){
	int sum=0;
	int k=0;

	struct stat sb;

	if (fstat(filp, &sb) == -1) 
	  handle_error("fstat");
	
	srand ( 2 );  //For true random else seeded
	int pos = rand();
	while (k<j){
		srand ( pos );
		pos = 0 + (rand() % static_cast<int>(sb.st_size - 0 + 1));
		seek(pos);
		int line_size = readln().size();	
		sum+=line_size;
		k++;
	}

	return sum; //returns the length of all the lines read 
}