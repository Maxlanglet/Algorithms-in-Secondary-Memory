#include <iostream>
#include <string>
#include <fstream>


using namespace std;


class OutputStream{
public:
	OutputStream(string filename);
	~OutputStream();
	void writeln1(string str, fstream &output_file);
    void writeln2(string str, fstream &output_file);
    void writeln3(string str, fstream &output_file);
    void writeln4(string str, fstream &output_file);
	void close();
	void create(string name_file);

private:
	string path;
	ofstream* new_file_pointer;// voir pq pas fstream
};