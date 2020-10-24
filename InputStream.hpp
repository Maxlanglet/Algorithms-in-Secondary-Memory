<<<<<<< Updated upstream
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
	void readln2();
	void readln3();
	void readln4();
	void seek(int pos);
	bool end_of_stream();
	void close();
private:
	string path;
	fstream file;
	
=======
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Abstract class representing the input streams
class InputStream{
public:
	InputStream(string filename);
	~InputStream();
	virtual void open();
	virtual void readln();
	virtual void seek(int pos);
	virtual bool end_of_stream();
	virtual void close();
>>>>>>> Stashed changes
};