#include "mergesort.hpp"

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)


bool compare(const string& first, const string& sec){
	//TODO: trouver moyen d'envoyer k ici

	int k =10;
	int i=k-1;
	if (tolower(first[i])<tolower(sec[i])) return true;
	else if (tolower(first[i])>tolower(sec[i])) return false;


	return ( first.length() < sec.length() );
}

mergesort::mergesort(){}


mergesort::~mergesort(){}

void mergesort::extsort(string inputfile, int k, int M, int d){
	//tester savoir quel outputstream utiliser ici, pour le moment outputstream1
	OutputStream1 outputstream1;


	InputStream2 instream2;
	instream2.open(inputfile.c_str());


	list<string> mylist;
	list<string> addresses;
	list<string>::iterator it;

	int j=0;

	column=k;

	//int size = instream2.length(); not necessary because we want lines

	//int nm = ceil(size/M);

	while(!instream2.end_of_stream()){
		outputstream1.create("outputfile"+to_string(j)+".txt");
		addresses.push_back("outputfile"+to_string(j)+".txt");

		int i =0;

		while(i<M){
			if (!instream2.end_of_stream()){
				string temp = instream2.readln();
				cout << temp;
				mylist.push_back(temp);
			}
			else{
				i=M;
			}
			i++;
		}

		mylist.sort(compare);

/*
		for (auto const &v : mylist){
			cout << v;
		}
*/
		for (it=mylist.begin(); it!=mylist.end(); ++it) outputstream1.writeln(*it);//enlever cout ici pour plus print dans terminal cout << *it, 

		mylist.clear();

		j++;
	}
	cout << j << endl;

}