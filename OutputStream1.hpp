#include <iostream>
#include <string>
#include <fstream>
#include "OutputStream.hpp"

using namespace std;


class OuputStream1{
public:
	OuputStream1(string filename);
	~OuputStream1();
	void writeln(string str, fstream &output_file);
	void close();
	void create(string name_file);

private:
	string path;
	ofstream* new_file_pointer;// voir pq pas fstream
};