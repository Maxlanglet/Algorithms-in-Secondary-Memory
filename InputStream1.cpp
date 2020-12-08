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
	// open the file
	filp = ::open(path.c_str(), O_RDONLY);	
}



//caractère par caractère
//peut etre faut il utiliser fonction read() de unistd mais pas reussis a faire fonctionner
//peut etre file.read(c,1)
int InputStream1::readln(){ //returns length of the read line  

	string line ="";
	int bytes_read =1;
	if (filp){
		
		char* c = (char*) malloc(sizeof(char));
		while( bytes_read > 0){//temporary but read the entire file
						
			bytes_read = read(filp, c, sizeof(char));		//buffer overwritten not flushed
			line += c;
			offset ++;
			if (*c == '\n' || *c == '\r'){
				return line.size();
			}
		}
		free(c);
	}else{
		cout << "File is not open" << endl;}

	if (bytes_read ==0){
		return 0;
	}
	else{
		return line.size();}
	
}

void InputStream1::seek(int pos){
	lseek (filp, pos, SEEK_SET);
}

bool InputStream1::end_of_stream(){
	int bytes_read = 1;

	if((bytes_read = lseek (filp, offset, SEEK_SET)) == -1){
		return true;
	}
	else{
		return false;
	}
}

void InputStream1::close(){
	::close(filp);
}

int InputStream1::length(string file){
	open(file);
	struct stat sb;

	if (fstat(filp, &sb) == -1) 
	  handle_error("fstat");
	cout << sb.st_size << endl;
	int line_size =1;
	int sum=0;
	while (line_size>0){
		line_size = readln();
		sum+=line_size;
	}
	return sum;
}


int InputStream1::randjump(string file, int j){//seems to work fine
	int sum=0;
	int k=0;


	open(file);
	struct stat sb;

	if (fstat(filp, &sb) == -1) 
	  handle_error("fstat");
	
	srand ( 2 );//for true random else seeded
	int pos = rand();

	while (k<j){
		srand ( pos );
		pos = 0 + (rand() % static_cast<int>(sb.st_size - 0 + 1));
		seek(pos);
		int line_size = readln();
		sum+=line_size;
		k++;
	}

	return sum;
}