#include <iostream>
#include <string>
#include <fstream>


using namespace std;


class InputStream{
public:
	InputStream(string filename);
	~InputStream();
	void open();
	void readln1();
	void seek(int pos);
	bool end_of_stream();
	void close();
private:
	string path;
	ifstream file;
	
};