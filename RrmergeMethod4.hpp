#ifndef RRMERGEMATHOD4_H
#define RRMERGEMATHOD4_H
#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>
#include <cstdarg>
#include <math.h> 
#include "InputStream2.hpp" ////change to 4
#include "OutputStream1.hpp"
#include "OutputStream2.hpp"
#include "OutputStream3.hpp"
//#include "OutputStream4.hpp"

using namespace std;


class RrmergeMethod4// : public InputStream pour interface mais ca fait des erreurs de partout alors j'enleve pour le moment
{
public:
	RrmergeMethod4();
	~RrmergeMethod4();
	void rrmerge1(string outputfile, int num, ... );
	void rrmerge2(string outputfile, int num, ... );
	void rrmerge3(string outputfile, int num, ... );
	void rrmerge4(string outputfile, int num, ... );
private:
	//InputStream4 instream4;
};
#endif