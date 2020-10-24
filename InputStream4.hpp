#include <iostream>
#include <string>
#include <fstream>
#include "InputStream.hpp"

using namespace std;


class InputStream4{
public:
	InputStream4(string filename);
	~InputStream4();
	void open();
	void readln();
	void seek(int pos);
	bool end_of_stream();
	void close();
private:
	string path;
	fstream file;
	
};