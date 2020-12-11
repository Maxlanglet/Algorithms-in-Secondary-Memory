#include "Timer.hpp"
#include "OutputStream1.hpp"
#include "InputStream1.hpp"
#include "OutputStream2.hpp"
#include "InputStream2.hpp"
#include "OutputStream3.hpp"
#include "InputStream3.hpp"
#include "OutputStream4.hpp"
#include "InputStream4.hpp"
#include "RrmergeMethod4.hpp"

int main(int argc, char* argv[]){

	//string title = "../imdb/aka_name.csv";//./role_type.csv//complete_cast.csv//
	//string title = "C:/Users/User/Downloads/MA1/DB ARCHITECTURE/projet/role_type.csv";
	string title = "./role_type.csv";
	/*printf("TEST INPUTSTREAM4\n\n");

 	InputStream4 instream4;
 	instream4.open(title.c_str());
 	instream4.seek(0);

	cout<<instream4.readln(1)<<endl;
	cout<<instream4.readln(1)<<endl;
	cout<<"salina"<<endl;
	
{
	Timer timer;
	cout << "length is " << instream4.length(title) << endl;
}

{
	Timer timer;
	cout << "sum rand is " << instream4.randjump(title,1000) << endl;
}
	instream4.close();*/



	printf("\nTEST INPUTSTREAM1\n\n");
	InputStream1 instream ; //if () considers it a function in main 
	instream.open(title.c_str());
	cout<<instream.readln()<<endl;
	//instream.close();
	
/*
{
	Timer timer;
	cout << "length is " << instream.length(title) << endl;
}

{
	Timer timer;
	cout << "sum rand is " << instream.randjump(title,1000) << endl;
}*/
	instream.close();

	printf("TEST RRMERGE4\n\n");
	RrmergeMethod4 r;
	r.rrmerge1("theoutput",2,"role_type.csv","test.csv");

/*

	printf("TEST INPUTSTREAM2\n\n");
	InputStream2 instream2 ; //if () considers it a function in main 
	instream2.open(title.c_str());
	instream2.seek(0);
	
	
{
	Timer timer;
	cout << "length is " << instream2.length(title) << endl;
}

{
	Timer timer;
	cout << "sum rand is " << instream2.randjump(title,1000) << endl;
}
	instream2.close();




	printf("TEST INPUTSTREAM3\n\n");
	InputStream3 instream3 ; //if () considers it a function in main 
	instream3.open(title.c_str());
	instream3.seek(0);
	
{
	Timer timer;
	cout << "length is " << instream3.length(title,4096) << endl;
}

{
	Timer timer;
	cout << "sum rand is " << instream3.randjump(title,1000,4096) << endl;
}

	instream3.close();
*/

	/*string title4="longasstext.txt";
	string title2= "testout.txt";
	OutputStream3 outstream3;
	outstream3.create(title2.c_str());
	outstream3.writeln("heololo");*/
	/*
	string title4="shorttext.txt";
	OutputStream4 outstream4(title4.c_str());
	outstream4.create();
	//outstream4.open2();
	string str = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus. Phasellus viverra nulla ut metus varius laoreet. Quisque rutrum. Aenean imperdiet. Etiam ultricies nisi vel augue. Curabitur ullamcorper ultricies nisi. Nam eget dui. Etiam rhoncus. Maecenas tempus, tellus eget condimentum rhoncus, sem quam semper libero, sit amet adipiscing sem neque sed ipsum. Nam quam nunc, blandit vel, luctus pulvinar, hendrerit id, lorem. Maecenas nec odio et ante tincidunt tempus. Donec vitae sapien ut libero venenatis faucibus. Nullam quis ante. Etiam sit amet orci eget eros faucibus tincidunt. Duis leo. Sed fringilla mauris sit amet nibh. Donec sodales sagittis magna. Sed consequat, leo eget bibendum sodales, augue velit cursus nunc, quis gravida magna mi a libero. Fusce vulputate eleifend sapien. Vestibulum purus quam, scelerisque ut, mollis sed, nonummy id, metus. Nullam accumsan lorem in dui. Cras ultricies mi eu turpis hendrerit fringilla. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; In ac dui quis mi consectetuer lacinia. Nam pretium turpis et arcu. Duis arcu tortor, suscipit eget, imperdiet nec, imperdiet iaculis, ipsum. Sed aliquam ultrices mauris. Integer ante arcu, accumsan a, consectetuer eget, posuere ut, mauris. Praesent adipiscing. Phasellus ullamcorper ipsum rutrum nunc. Nunc nonummy metus. Vestibulum volutpat pretium libero. Cras id dui. Aenean ut eros et nisl sagittis vestibulum. Nullam nulla eros, ultricies sit amet, nonummy id, imperdiet feugiat, pede. Sed lectus. Donec mollis hendrerit risus. Phasellus nec sem in justo pellentesque facilisis. Etiam imperdiet imperdiet orci. Nunc nec neque. Phasellus leo dolor, tempus non, auctor et, hendrerit quis, nisi. Curabitur ligula sapien, tincidunt non, euismod vitae, posuere imperdiet, leo. Maecenas malesuada. Praesent congue erat at massa. Sed cursus turpis vitae tortor. Donec posuere vulputate arcu. Phasellus accumsan cursus velit. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Sed aliquam, nisi quis porttitor congue, elit erat euismod orci, ac placerat dolor lectus quis orci. Phasellus consectetuer vestibulum elit. Aenean tellus metus, bibendum sed, posuere ac, mattis non, nunc. Vestibulum fringilla pede sit amet augue. In turpis. Pellentesque posuere. Praesent turpis. Aenean posuere, tortor sed cursus feugiat, nunc augue blandit nunc, eu sollicitudin urna dolor sagittis lacus. Donec elit libero, sodales nec, volutpat a, suscipit non, turpis. Nullam sagittis. Suspendisse pulvinar, augue ac venenatis condimentum, sem libero volutpat nibh, nec pellentesque velit pede quis nunc. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Fusce id purus. Ut varius tincidunt libero. Phasellus dolor. Maecenas vestibulum mollis diam. Pellentesque ut neque. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. In dui magna, posuere eget, vestibulum et, tempor auctor, justo. In ac felis quis tortor malesuada pretium. Pellentesque auctor neque nec urna. Proin sapien ipsum, porta a, auctor quis, euismod ut, mi. Aenean viverra rhoncus pede. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Ut non enim eleifend felis pretium feugiat. Vivamus quis mi. Phasellus a est. Phasellus magna. In hac habitasse platea dictumst. Curabitur at lacus ac velit ornare lobortis. Cura yoyooyoyoyo";
	//string str = "hello";
	outstream4.writeln(str.c_str());
	outstream4.close2();
	*/
	return 0;
}