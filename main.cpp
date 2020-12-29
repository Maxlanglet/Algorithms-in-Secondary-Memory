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

//#include <cstdlib>

#include <string>

int main(int argc, char* argv[]){
/*
	RrmergeMethod2 r2 ;
	r2.rrmerge1("output21.txt",3,"t1.txt","t2.txt","t3.txt");
	r2.rrmerge2("output22.txt",3,"t1.txt","t2.txt","t3.txt");
	r2.rrmerge3("output23.txt",10,3,"t1.txt","t2.txt","t3.txt");
	r2.rrmerge4("output24.txt",1,3,"t1.txt","t2.txt","t3.txt");
	
	RrmergeMethod3 r4 ;
	r4.rrmerge1("output31.txt",10,3,"t1.txt","t2.txt","t3.txt");
	r4.rrmerge2("output32.txt",10,3,"t1.txt","t2.txt","t3.txt");
	r4.rrmerge3("output33.txt",10,10,3,"t1.txt","t2.txt","t3.txt");
	r4.rrmerge4("output34.txt",10,1,3,"t1.txt","t2.txt","t3.txt");
	
	*/
	/*int size = atoi(argv[2]);

	string name = argv[1];

	string title = name;
	cout << title << endl;
	cout << "Method|Size of buffer |Characters read| average| average speed"<< endl;*/
	
	//int buffer[] = {1, 2, 3,10, 100, 1000};

	//string title = "/Users/langletmaxime/Desktop/Database_Systems_Architecture/Algorithms_in_Secondary_Memory/imdb/cast_info.csv";

	//int size = 10000;

/*
	//printf("\nTEST INPUTSTREAM1\n\n");
	InputStream1 instream ; //if () considers it a function in main 
	instream.open("role_type.csv");


float average=0;
int length =0;
for(int i=0; i<4; i++){
	Timer timer;
	length = instream.randjump(title,size);
	timer.Stop();
	average+=timer.getDuration();
}
cout << "1 "<<" & ";
cout << size << " & ";
cout << length << " & ";
cout <<  average/4 << " & "<< length/(average/4) << " \\\\" << endl;

instream.close();
*/
/*
	//printf("TEST INPUTSTREAM2\n\n");
	InputStream2 instream2 ; //if () considers it a function in main 
	instream2.open(title.c_str());
	instream2.seek(0);
	
	
float average2=0;
int length2 =0;
for(int i=0; i<4; i++){
	Timer timer;
	length2 = instream2.length();
	timer.Stop();
	average2+=timer.getDuration();
}
cout << "2 "<<" & ";
cout << " & "<< length2 << " & ";
cout <<  average2/4 << " & "<< length2/(average2/4) << " \\\\" << endl;


	instream2.close();
*/
/*
{
	//printf("TEST INPUTSTREAM3\n\n");
	InputStream3 instream3 ; //if () considers it a function in main 
	instream3.open(title.c_str());
	instream3.seek(0);
	
float average3=0;
int length3=0;
for(int i=0; i<4; i++){
	Timer timer;
	length3 =  instream3.randjump("", size, buffer[0]*4096);
	cout << length3 << endl;
	timer.Stop();
	average3+=timer.getDuration();
}
cout << "3 "<<" & ";
cout << " & "<< length3 << " & ";
cout <<  average3/4 << " & "<< length3/(average3/4) << " \\\\" << endl;


{
	Timer timer;
	cout << "sum rand is " << instream3.randjump(title,1000,size) << endl;
}

	instream3.close();
}
*/
/*
	//string title = "./role_type.csv";
	int mul=1;

	if (size >= 4096){
		mul = size/4096;
		//cout << mul<<endl;
	}
*/
	//printf("TEST INPUTSTREAM4\n\n");
/*
	InputStream4 instream4;
 	instream4.open(title.c_str());
 	instream4.seek(0);

	float average4=0;
	int length4=0;

	for(int j=0; j<6; j++){
		for(int i=0; i<4; i++){
			Timer timer;
			//length4 = instream4.length(mul);
			length4 = instream4.randjump(size, buffer[j]);
			timer.Stop();
			average4+=timer.getDuration();
		}
		
	cout <<size << " & " << buffer[j]*4096;
	//cout << "4 "<<" & " << size;
	cout << " & "<< length4 << " & ";
	cout <<  average4/4 << " & "<< length4/(average4/4) << " \\\\" << endl;
	}

	instream4.close();

	cout << "\\hline" << endl;
}*/
/*
{	
	printf("TEST RRMERGE2\n\n");
	RrmergeMethod2 r;

	struct stat sb;
	int file = open(title.c_str(), O_RDONLY);
	fstat(file, &sb);
	int init =  sb.st_size;

	cout << init << endl;

//=============================================================================
	/*cout << "METHOD 1: " << endl;

	int average=0;

	for(int i=0; i<2; i++){
		Timer timer;
		//length4 = instream4.length(mul);
		r.rrmerge1("theoutput1.txt",2,title.c_str(),title.c_str());
		timer.Stop();
		average+=timer.getDuration();
	}
	cout << "average time: " << average/2 << endl;

	file = open("theoutput1.txt", O_RDONLY);

	fstat(file, &sb);
	int fin =  sb.st_size;

	cout << "size of init compared to final: " <<  init << " " << fin << endl;*/

//=============================================================================
	/*cout << "METHOD 2: " << endl;

	int average2=0;

	for(int i=0; i<2; i++){
		Timer timer;
		//length4 = instream4.length(mul);
		r.rrmerge2("theoutput2.txt",2,title.c_str(),title.c_str());
		timer.Stop();
		average2+=timer.getDuration();
	}
	cout << "average time: " << average2/2 << endl;

	int fd = open("theoutput2.txt", O_RDONLY);

	off_t pos2 = lseek(fd, 0, SEEK_END);

	cout << "size of init compared to final: " <<  init << " " << pos2 << endl;
}*/

//=============================================================================
	/*cout << "METHOD 3: " << endl;

	int average3=0;

	for(int i=0; i<2; i++){
		Timer timer;
		//length4 = instream4.length(mul);
		r.rrmerge3("theoutput3.txt",size,2,title.c_str(),title.c_str());
		timer.Stop();
		average3+=timer.getDuration();
	}
	cout << "average time: " << average3/2 << " with buffer size:" << size << endl;

	file = open("theoutput3.txt", O_RDONLY);

	fstat(file, &sb);
	int fin3 =  sb.st_size;

	cout << "size of init compared to final: " <<  init << " " << fin3 << endl;*/

//=============================================================================
	/*cout << "METHOD 4: " << endl;

	int average4=0;

	for(int i=0; i<2; i++){
		Timer timer;
		//length4 = instream4.length(mul);
		r.rrmerge4("theoutput4.txt",size,2,title.c_str(),title.c_str());
		timer.Stop();
		average4+=timer.getDuration();
	}
	cout << "average time: " << average4/2 << " with buffer size:" << size << endl;

	file = open("theoutput4.txt", O_RDONLY);


	fstat(file, &sb);
	int fin4 =  sb.st_size;

	cout << "size of init compared to final: " <<  init << " " << fin4 << endl;
	
}*/


/*
	printf("TEST MERGESORT\n\n");
	class mergesort msort;
	//msort.extsort("../imdb/info_type.csv", 3, 10, 2, 50);

	struct stat sb;

	int file = open("movie_link.csv", O_RDONLY);	

	fstat(file, &sb);
	int init =  sb.st_size;

	//msort.extsort("movie_link.csv", 3, 10000, 30,50);


	file = open("mergedfile0_0.txt", O_RDONLY);	

	fstat(file, &sb);
	cout << init <<sb.st_size << endl;
	//msort.extsort("movie_link.csv", 3, 60, 30,50);
	msort.extsort("complete_cast.csv", 4, 1000, 500,50);
	//msort.extsort("role_type.csv", 5, 10,5,50);
	//msort.extsort("mergedfile0_0 copy.txt", 1, 10,5,50);*/

/*	printf("TEST RRMERGE2\n\n");
	RrmergeMethod2 r2;
	RrmergeMethod3 r4;*/


	//r.rrmerge1("2theoutput1.txt",2,"../imdb/info_type.csv","../imdb/role_type.csv");//2,"test.csv"
	//r.rrmerge2("2theoutput2.txt",2,"../imdb/info_type.csv","../imdb/role_type.csv");
	//r.rrmerge3("2theoutput3.txt",10,2,"../imdb/info_type.csv","../imdb/role_type.csv");
	//r2.rrmerge4("2theoutput4.txt",10,2,2,"info_type.csv","role_type.csv");
	//r4.rrmerge4("3theoutput4.txt",10,2,2,"info_type.csv","role_type.csv");

//r.rrmerge1("2theoutput1.txt",2,"info_type.csv","role_type.csv");//2,"test.csv"
//	r.rrmerge2("2theoutput2.txt",2,"info_type.csv","role_type.csv");
//	r.rrmerge3("2theoutput3.txt",10,2,"info_type.csv","role_type.csv");
	//r2.rrmerge4("2theoutput4.txt",10,2,"info_type.csv","role_type.csv");
	
	
/*


	r2.rrmerge2("2theoutput2.txt",2,"../imdb/info_type.csv","../imdb/role_type.csv");


	r2.rrmerge3("theoutput3.txt",10,2,"info_type.csv","role_type.csv");


	r2.rrmerge4("theoutput4.txt",10,2,"info_type.csv","role_type.csv");
*/
/*
	string title4="longasstext.txt";
	string title2= "testout.txt";
	OutputStream3 outstream3;
	outstream3.create(title2.c_str());
	outstream3.writeln("heololo", 20);
	string str = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus. Phasellus viverra nulla ut metus varius laoreet. Quisque rutrum. Aenean imperdiet. Etiam ultricies nisi vel augue. Curabitur ullamcorper ultricies nisi. Nam eget dui. Etiam rhoncus. Maecenas tempus, tellus eget condimentum rhoncus, sem quam semper libero, sit amet adipiscing sem neque sed ipsum. Nam quam nunc, blandit vel, luctus pulvinar, hendrerit id, lorem. Maecenas nec odio et ante tincidunt tempus. Donec vitae sapien ut libero venenatis faucibus. Nullam quis ante. Etiam sit amet orci eget eros faucibus tincidunt. Duis leo. Sed fringilla mauris sit amet nibh. Donec sodales sagittis magna. Sed consequat, leo eget bibendum sodales, augue velit cursus nunc, quis gravida magna mi a libero. Fusce vulputate eleifend sapien. Vestibulum purus quam, scelerisque ut, mollis sed, nonummy id, metus. Nullam accumsan lorem in dui. Cras ultricies mi eu turpis hendrerit fringilla. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; In ac dui quis mi consectetuer lacinia. Nam pretium turpis et arcu. Duis arcu tortor, suscipit eget, imperdiet nec, imperdiet iaculis, ipsum. Sed aliquam ultrices mauris. Integer ante arcu, accumsan a, consectetuer eget, posuere ut, mauris. Praesent adipiscing. Phasellus ullamcorper ipsum rutrum nunc. Nunc nonummy metus. Vestibulum volutpat pretium libero. Cras id dui. Aenean ut eros et nisl sagittis vestibulum. Nullam nulla eros, ultricies sit amet, nonummy id, imperdiet feugiat, pede. Sed lectus. Donec mollis hendrerit risus. Phasellus nec sem in justo pellentesque facilisis. Etiam imperdiet imperdiet orci. Nunc nec neque. Phasellus leo dolor, tempus non, auctor et, hendrerit quis, nisi. Curabitur ligula sapien, tincidunt non, euismod vitae, posuere imperdiet, leo. Maecenas malesuada. Praesent congue erat at massa. Sed cursus turpis vitae tortor. Donec posuere vulputate arcu. Phasellus accumsan cursus velit. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Sed aliquam, nisi quis porttitor congue, elit erat euismod orci, ac placerat dolor lectus quis orci. Phasellus consectetuer vestibulum elit. Aenean tellus metus, bibendum sed, posuere ac, mattis non, nunc. Vestibulum fringilla pede sit amet augue. In turpis. Pellentesque posuere. Praesent turpis. Aenean posuere, tortor sed cursus feugiat, nunc augue blandit nunc, eu sollicitudin urna dolor sagittis lacus. Donec elit libero, sodales nec, volutpat a, suscipit non, turpis. Nullam sagittis. Suspendisse pulvinar, augue ac venenatis condimentum, sem libero volutpat nibh, nec pellentesque velit pede quis nunc. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Fusce id purus. Ut varius tincidunt libero. Phasellus dolor. Maecenas vestibulum mollis diam. Pellentesque ut neque. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. In dui magna, posuere eget, vestibulum et, tempor auctor, justo. In ac felis quis tortor malesuada pretium. Pellentesque auctor neque nec urna. Proin sapien ipsum, porta a, auctor quis, euismod ut, mi. Aenean viverra rhoncus pede. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Ut non enim eleifend felis pretium feugiat. Vivamus quis mi. Phasellus a est. Phasellus magna. In hac habitasse platea dictumst. Curabitur at lacus ac velit ornare lobortis. Cura yoyooyoyoyo";
	//string str = "hello";
	outstream3.writeln(str.c_str(), 200);
	str = "hello";
	outstream3.writeln(str.c_str(), 2);
	outstream3.close();*/
	
	string title4="shorttext.txt";
	OutputStream4 outstream4;
	outstream4.create(title4.c_str());
	//outstream4.open2();
	string str = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus. Phasellus viverra nulla ut metus varius laoreet. Quisque rutrum. Aenean imperdiet. Etiam ultricies nisi vel augue. Curabitur ullamcorper ultricies nisi. Nam eget dui. Etiam rhoncus. Maecenas tempus, tellus eget condimentum rhoncus, sem quam semper libero, sit amet adipiscing sem neque sed ipsum. Nam quam nunc, blandit vel, luctus pulvinar, hendrerit id, lorem. Maecenas nec odio et ante tincidunt tempus. Donec vitae sapien ut libero venenatis faucibus. Nullam quis ante. Etiam sit amet orci eget eros faucibus tincidunt. Duis leo. Sed fringilla mauris sit amet nibh. Donec sodales sagittis magna. Sed consequat, leo eget bibendum sodales, augue velit cursus nunc, quis gravida magna mi a libero. Fusce vulputate eleifend sapien. Vestibulum purus quam, scelerisque ut, mollis sed, nonummy id, metus. Nullam accumsan lorem in dui. Cras ultricies mi eu turpis hendrerit fringilla. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; In ac dui quis mi consectetuer lacinia. Nam pretium turpis et arcu. Duis arcu tortor, suscipit eget, imperdiet nec, imperdiet iaculis, ipsum. Sed aliquam ultrices mauris. Integer ante arcu, accumsan a, consectetuer eget, posuere ut, mauris. Praesent adipiscing. Phasellus ullamcorper ipsum rutrum nunc. Nunc nonummy metus. Vestibulum volutpat pretium libero. Cras id dui. Aenean ut eros et nisl sagittis vestibulum. Nullam nulla eros, ultricies sit amet, nonummy id, imperdiet feugiat, pede. Sed lectus. Donec mollis hendrerit risus. Phasellus nec sem in justo pellentesque facilisis. Etiam imperdiet imperdiet orci. Nunc nec neque. Phasellus leo dolor, tempus non, auctor et, hendrerit quis, nisi. Curabitur ligula sapien, tincidunt non, euismod vitae, posuere imperdiet, leo. Maecenas malesuada. Praesent congue erat at massa. Sed cursus turpis vitae tortor. Donec posuere vulputate arcu. Phasellus accumsan cursus velit. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Sed aliquam, nisi quis porttitor congue, elit erat euismod orci, ac placerat dolor lectus quis orci. Phasellus consectetuer vestibulum elit. Aenean tellus metus, bibendum sed, posuere ac, mattis non, nunc. Vestibulum fringilla pede sit amet augue. In turpis. Pellentesque posuere. Praesent turpis. Aenean posuere, tortor sed cursus feugiat, nunc augue blandit nunc, eu sollicitudin urna dolor sagittis lacus. Donec elit libero, sodales nec, volutpat a, suscipit non, turpis. Nullam sagittis. Suspendisse pulvinar, augue ac venenatis condimentum, sem libero volutpat nibh, nec pellentesque velit pede quis nunc. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Fusce id purus. Ut varius tincidunt libero. Phasellus dolor. Maecenas vestibulum mollis diam. Pellentesque ut neque. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. In dui magna, posuere eget, vestibulum et, tempor auctor, justo. In ac felis quis tortor malesuada pretium. Pellentesque auctor neque nec urna. Proin sapien ipsum, porta a, auctor quis, euismod ut, mi. Aenean viverra rhoncus pede. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Ut non enim eleifend felis pretium feugiat. Vivamus quis mi. Phasellus a est. Phasellus magna. In hac habitasse platea dictumst. Curabitur at lacus ac velit ornare lobortis. Cura yoyooyoyoyo";
	//string str = "hello";
	outstream4.writeln(str.c_str(),4096);
	cout << "NEW WRITE"<<endl;
	outstream4.writeln(str.c_str(),8000);
	str = "hello";
	cout << "NEW WRITE HELLO"<<endl;
	outstream4.writeln(str.c_str(),8000);
	cout << "NEW WRITE"<<endl;
	outstream4.writeln(str.c_str(),80);
	outstream4.close2();
	
	return 0;
}