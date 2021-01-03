#include "Timer.hpp"
#include "OutputStream1.hpp"
#include "InputStream1.hpp"
#include "OutputStream2.hpp"
#include "InputStream2.hpp"
#include "OutputStream3.hpp"
#include "InputStream3.hpp"
#include "OutputStream4.hpp"
#include "InputStream4.hpp"
#include "RrmergeMethod3.hpp"
#include "RrmergeMethod2.hpp"
#include "mergesort.hpp"

#include <string>

int main(int argc, char* argv[]){		//DISCLAIMER : DO NOT RUN RUN THE MAIN THIS WAY
										//comment out the methods you do not want to test
	
	//to read input from the python script
	int size = atoi(argv[2]);

	string name = argv[1];

	string title = name;

	cout << title << endl;
	cout << "Method|Size of buffer |Characters read| average| average speed"<< endl;


	
	
	int buffer[] = {1, 2, 3,10, 100, 1000};//required when testing randjump


//===========================================================================
//===========================================================================

{
	//printf("\nTEST INPUTSTREAM1\n\n");//=================================================
	InputStream1 instream ;
	instream.open(title.c_str());
	instream.seek(0);


float average=0;
int length =0;
for(int i=0; i<4; i++){
	Timer timer;
	length = instream.randjump(size);
	//length = instream.length();//when length is tested
	timer.Stop();
	average+=timer.getDuration();
}
//stdout for easy print in our Latex file

cout << "1 "<<" & ";
cout << size << " & ";
cout << length << " & ";
cout <<  average/4 << " & "<< length/(average/4) << " \\\\" << endl;

instream.close();
}
{
	//printf("TEST INPUTSTREAM2\n\n");==================================================
	InputStream2 instream2 ; 
	instream2.open(title.c_str());
	instream2.seek(0);
	
	
float average2=0;
int length2 =0;
for(int i=0; i<4; i++){
	Timer timer;
	length2 = instream2.randjump(size);
	//length2 = instream2.length();
	timer.Stop();
	average2+=timer.getDuration();
}
cout << "2 "<<" & ";
cout << " & "<< length2 << " & ";
cout <<  average2/4 << " & "<< length2/(average2/4) << " \\\\" << endl;


	instream2.close();

}
{
	//printf("TEST INPUTSTREAM3\n\n");==============================================
	InputStream3 instream3 ;
	instream3.open(title.c_str());
	instream3.seek(0);
	
//length loop
float average3=0;
int length3=0;
for(int i=0; i<4; i++){
	Timer timer;
	length3 = instream3.length(size);
	timer.Stop();
	average3+=timer.getDuration();
}
cout << "3 "<<" & "<< size;
cout << " & "<< length3 << " & ";
cout <<  average3/4 << " & "<< length3/(average3/4) << " \\\\" << endl;

/*//randjump loop
for(int j=0; j<6; j++){
		for(int i=0; i<4; i++){
			Timer timer;
			length3 = instream3.randjump(size, buffer[j]);
			timer.Stop();
			average3+=timer.getDuration();
		}
		
	cout <<size << " & " << buffer[j]*4096;
	//cout << "4 "<<" & " << size;
	cout << " & "<< length3 << " & ";
	cout <<  average3/4 << " & "<< length3/(average3/4) << " \\\\" << endl;
	}
*/

	instream3.close();
}
{
	//page multiple for Input Stream 4
	int mul=1;

	if (size >= 4096){
		mul = size/4096;
		cout << mul<<endl;
	}

	//printf("TEST INPUTSTREAM4\n\n");======================================

	InputStream4 instream4;
 	instream4.open(title.c_str());
 	instream4.seek(0);

	float average4=0;
	int length4=0;

	//Loop for testing length
	for(int i=0; i<4; i++){
		Timer timer;
		length4 = instream4.length(mul);
		timer.Stop();
		average4+=timer.getDuration();
	}
	cout << "4 "<<" & " << size;
	cout << " & "<< length4 << " & ";
	cout <<  average4/4 << " & "<< length4/(average4/4) << " \\\\" << endl;
	instream4.close();

	cout << "\\hline" << endl;

/*	//Loop to test rand jump of Input Stream 4
	for(int j=0; j<6; j++){
		for(int i=0; i<4; i++){
			Timer timer;
			//length4 = instream4.length(mul);
			length4 = instream4.randjump(size, buffer[j]);
			timer.Stop();
			average4+=timer.getDuration();
		}
		
	cout <<size << " & " << buffer[j]*4096;
	cout << " & "<< length4 << " & ";
	cout <<  average4/4 << " & "<< length4/(average4/4) << " \\\\" << endl;
	}
	*/
}



//===========================================================================
//===========================================================================

	printf("TEST RRMERGE2\n\n");
	RrmergeMethod2 r;

	struct stat sb;
	int file = open(title.c_str(), O_RDONLY);
	fstat(file, &sb);
	int init =  sb.st_size;

	cout << init << endl;//print size of the file

//=============================================================================
{
	//cout << "METHOD 1: " << endl;

	int average=0;

	for(int i=0; i<4; i++){
		Timer timer;
		//r.rrmerge1("theoutput1.txt",1000,2,title.c_str(),title.c_str());//when testing Rrmerge3
		r.rrmerge1("theoutput1.txt",2, title.c_str(),title.c_str());
		timer.Stop();
		average+=timer.getDuration();
	}

	file = open("theoutput1.txt", O_RDONLY);

	fstat(file, &sb);
	int fin =  sb.st_size;

	cout << " & " << " 1 " << " & / & " << fin << " & " << average/4 << " \\\\" << endl;
	
}

//=============================================================================
{
	//cout << "METHOD 2: " << endl;

	int average2=0;

	for(int i=0; i<4; i++){
		Timer timer;
		//r.rrmerge2("theoutput2.txt",1000,2,title.c_str(),title.c_str());//when testing Rrmerge3
		r.rrmerge2("theoutput2.txt",2,title.c_str(),title.c_str());
		timer.Stop();
		average2+=timer.getDuration();
	}

	int file = open("theoutput2.txt", O_RDONLY);


	fstat(file, &sb);
	int fin =  sb.st_size;

	cout << " & " << " 2 " << " & / & " << fin << " & " << average2/4<< " \\\\" << endl;

}

//=============================================================================

{
	//cout << "METHOD 3: " << endl;

	int average3=0;

	for(int i=0; i<4; i++){
		Timer timer;
		//r.rrmerge3("theoutput3.txt",1000,size,2,title.c_str(),title.c_str());//when testing Rrmerge3
		r.rrmerge3("theoutput3.txt",size,3,title.c_str(),title.c_str());
		timer.Stop();
		average3+=timer.getDuration();
	}

	int file = open("theoutput3.txt", O_RDONLY);

	fstat(file, &sb);
	int fin =  sb.st_size;

	cout << " & " << " 3 " << " & "<< size <<" & " << fin << " & " << average3/4 << " \\\\"<< endl;

}

//=============================================================================
{
	//cout << "METHOD 4: " << endl;

	int average4=0;

	for(int i=0; i<4; i++){
		Timer timer;
		//r.rrmerge4("theoutput4.txt",1000,size,2,title.c_str(),title.c_str());//when testing Rrmerge3
		r.rrmerge4("theoutput4.txt",size,3,title.c_str(),title.c_str());
		timer.Stop();
		average4+=timer.getDuration();
	}

	file = open("theoutput4.txt", O_RDONLY);


	fstat(file, &sb);
	int fin4 =  sb.st_size;

	cout << " & " << " 4 " << " & "<< size <<" & " << fin4 << " & " << average4/4 << " \\\\"<< endl;
	

}
	
//===========================================================================
//===========================================================================
{
	//int buffer[] = {5,10,25,50,100};//100,500,1000,
	int buffer[] = {5,6,7,8,9,10,11,12,13,14,15};

	printf("TEST MERGESORT\n\n");
	class mergesort msort;

	struct stat sb;

	int file = open(title.c_str(), O_RDONLY);	

	fstat(file, &sb);
	int init =  sb.st_size;

	close(file);

	int average=0;
	cout << "d   M  average time" << endl;
	for(int j=0;j<11;j++){
		for(int i=0;i<4;i++){
			Timer timer;
			msort.extsort(title.c_str(), 4, size, buffer[j]);
			timer.Stop();
			average+=timer.getDuration();
		}
		cout << buffer[j] << " & " << size << " & " << average/4<< " \\\\"<<  endl;
	}


	file = open("mergedfile0_0.txt", O_RDONLY);	

	fstat(file, &sb);
	cout << "characters comparaison :"<< init <<sb.st_size << endl;
}

	return 0;
}