#include <iostream>
#include <string>
#include <fstream>
#include "InputStream.hpp"

using namespace std;


class InputStream1{
public:
	InputStream1(string filename);
	~InputStream1();
	void open();
	void readln();
	void seek(int pos);
	bool end_of_stream();
	void close();
private:
	string path;
	fstream file;
	
};