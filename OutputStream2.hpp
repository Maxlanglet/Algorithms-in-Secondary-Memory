#include <iostream>
#include <string>
#include <fstream>
#include "OutputStream.hpp"

using namespace std;


class OuputStream2{
public:
	OuputStream2(string filename);
	~OuputStream2();
	void writeln(string str, fstream &output_file);
	void close();
	void create(string name_file);

private:
	string path;
	ofstream* new_file_pointer;// voir pq pas fstream
};