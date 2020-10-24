#include <iostream>
#include <string>
#include <fstream>
#include "InputStream.hpp"

using namespace std;


class InputStream2{
public:
	InputStream2(string filename);
	~InputStream2();
	void open();
	void readln();
	void seek(int pos);
	bool end_of_stream();
	void close();
private:
	string path;
	fstream file;
	
};