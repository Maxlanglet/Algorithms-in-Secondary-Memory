#include "InputStream3.hpp"


#define BUFFER_SIZE 5


#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)

InputStream3::InputStream3(){
	offset = 0;
}

InputStream3::~InputStream3(){}

void InputStream3::open(string path){
	fd = ::open(path.c_str(), O_RDONLY);
	if (!fd) { printf("Error: could not open file %s\n", path.c_str());}
}

//buffer by buffer
string InputStream3::readln(int buf_size){//TODO: probleme length 3
	int buffer_size=buf_size;

	if (fd){

		ssize_t bytes_read =1;
		char* buffer = (char*) malloc(buffer_size*sizeof(char));


		if (!buffer) {
			printf("ERROR");
			exit(1);
		}
		size_t nbytes = buffer_size*sizeof(char);
		int sizeline = 0;
		string str="";

		offset = lseek(fd, 0, SEEK_CUR);

		struct stat sb;

		if (fstat(fd, &sb) == -1) 
	  		handle_error("fstat");

	  	int rest = sb.st_size - offset;

		char *p = NULL;
		bool edl=false;
		
		while(!edl && bytes_read >0){
			ssize_t idx = 0;

			if ((bytes_read = lseek (fd, offset, SEEK_SET)) != -1)
				bytes_read =  read(fd, buffer, nbytes);

			
			if (bytes_read == -1) {   /* read error   */
				cout << "Error" << endl;
		    }

		    p = buffer;
		    while (idx < bytes_read && *p != '\n' && *p != '\r') str+=*p,p++, idx++;
			//cout<<str<<endl;


		    if ( *p == '\n'){
		    	offset += idx +1;
		    	lseek(fd, offset, SEEK_SET);
				sizeline+=idx+1;
				str+="\n";
				edl=true;
				rest-=offset;
		    }
		    else{ 
				offset += idx;
				sizeline+=idx;
				lseek(fd, offset, SEEK_SET);
				rest-=offset;
			}
		free(buffer);
		}
		return str;
	}
	else{
		cout << "File is not open" << endl;
		exit(1);
	}

}

int InputStream3::length(string filename,int buf_size){
	open(filename);
	int sum = 0 ;
	int line_size = 1 ;
	struct stat sb;
	seek(0);

	if (fstat(fd, &sb) == -1) 
	  handle_error("fstat");

	 while (line_size > 0 ){
		line_size = readln(buf_size).size();
		sum += line_size ;
	 }
	 return sum ;
}

void InputStream3::seek(int pos){
	lseek (fd, pos, SEEK_SET);
}

bool InputStream3::end_of_stream(){
	int bytes_read = 1;

	if((bytes_read = lseek (fd, offset, SEEK_SET)) == -1){
		return true;
	}
	else{
		return false;
	}
}

void InputStream3::close(){
	//file.close();
	::close(fd);
}

int InputStream3::randjump(string file, int j, int buffer){
	int sum=0;
	int k=0;

	open(file);
	struct stat sb;
	seek(0);

	if (fstat(fd, &sb) == -1) 
	  handle_error("fstat");
	int line_size = 1 ;

	srand ( 2 );
	int pos = rand();
	
	while (k<j){
		srand ( pos );
		pos = 0 + (rand() % static_cast<int>(sb.st_size - 0 + 1));
		seek(pos);
		line_size = readln(buffer).size();
		sum+=line_size;
		k++;
	}
	return sum;
}


