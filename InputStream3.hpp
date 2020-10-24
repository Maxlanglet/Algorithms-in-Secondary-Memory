#include <iostream>
#include <string>
#include <fstream>
#include "InputStream.hpp"

using namespace std;


class InputStream3{
public:
	InputStream3(string filename);
	~InputStream3();
	void open();
	void readln();
	void seek(int pos);
	bool end_of_stream();
	void close();
private:
	string path;
	fstream file;
	
};