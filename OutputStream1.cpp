#include "OutputStream1.hpp"



OutputStream1::OutputStream1(){
}

OutputStream1::~OutputStream1(){}


void OutputStream1::create(string path){
	new_file = open(path.c_str(), O_CREAT | O_WRONLY | O_TRUNC,S_IWUSR |S_IRUSR);
	if (new_file < 0) {
		cout<<errno<<endl;
		printf("Error creating output file\n");
		exit(1);
    }
	
}


void OutputStream1::writeln(string str){//pour respliquer le vis a vis avec le input 1
	str+="\n";
	
	for (int i=0; i<str.length();i++){
		ssize_t n = write(new_file, &str[i], sizeof(char));
		if (n != sizeof(char)){
			printf("Error writing output file\n");
			break;
		}
		/*
		line += str[i];
		if (str[i] == '\n' || i==str.length()-1){
			ssize_t n = write(new_file, &line, sizeof(line));
			cout << line << endl;
			line = "";
			
		}
		*/
	}

}

void OutputStream1::close(){
	::close(new_file);
}

