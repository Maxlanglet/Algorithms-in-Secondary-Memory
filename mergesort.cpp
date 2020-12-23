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


struct Line
{
    string line;
	char kchar;
	Line(string l, int k):line(l), kchar(line[k]){}
};


struct LineComparator
{
    // Compare 2 Line objects using name
    bool operator ()(const Line & line1, const Line & line2)
    {
        if(line1.kchar == line2.kchar)
            return line1.kchar < line2.kchar;
        return line1.kchar < line2.kchar;
    }
};


mergesort::mergesort(){}


mergesort::~mergesort(){}

void mergesort::extsort(string inputfile, int k, int M, int d){
	//tester savoir quel outputstream utiliser ici, pour le moment outputstream1
	OutputStream1 outputstream1;


	InputStream2 instream2;
	instream2.open(inputfile.c_str());


	list<Line> mylist;
	list<string> addresses;
	list<Line>::iterator it;

	int j=0;

	column=k;

	//int size = instream2.length(); not necessary because we want lines

	//int nm = ceil(size/M);

	// read the whole file, put in numberoflines/M files and sort them on the k character
	while(!instream2.end_of_stream()){
		outputstream1.create("outputfile"+to_string(j)+".txt");
		addresses.push_back("outputfile"+to_string(j)+".txt");//ca devrait pas être une liste de pointeurs?

		int i =0;

		while(i<M){
			if (!instream2.end_of_stream()){//toujours vérifié
				string temp = instream2.readln();
				cout << temp;
				Line line_to_add = Line(temp, k);
				cout << line_to_add.kchar << endl;
				mylist.push_back(line_to_add);
				
			}
			else{
				i=M;
			}
			i++;
		}
//FAIRE LE CAS SI JAMAIS K DEPASSE
		mylist.sort(LineComparator());
		it = mylist.begin();
		for (int i = 0; i < mylist.size()-2; ++i)
		{
			outputstream1.writeln(it->line);
			++it;
			assert(it != mylist.end());
		}
			mylist.clear();

			j++;

/*
		for (auto const &v : mylist){
			cout << v;
		}
*/

		//for (it=mylist.begin(); it!=mylist.end(); ++it) outputstream1.writeln(it->line);
		/*for (it=mylist.begin(); it!=mylist.end(); ++it){
			string next = *it;
			int ite= ;
			it = mylist.erase(it);
			outputstream1.writeln(next->line);//enlever cout ici pour plus print dans terminal cout << *it,
			mylist.push_front(next);
		} */

	/*it = mylist.begin();
    while(it != mylist.end())
    {
		string fileline = it->line;
        outputstream1.writeln(fileline);
        it++;
    }*/

		/*for(int w = 0; w <mylist.length();w++){
			outputstream1.writeln(mylist[w]);

		}*/

	}
	cout << j << endl;
	instream2.close();
	//int y=0;
	int x=0;
	string s;
	while(addresses.size()!=1){
		// number of files in addresses in this pass
		int number_of_files = ceil(addresses.size()/d);
		
		// merge d files, x is the pass we are at, y is the number of the file in that pass
		for(int y; y<number_of_files; y++){
			//OutputStream1 outputstream1_merge;
			//InputStream2 instream2_merge;
			outputstream1.create("mergedfile"+to_string(x)+"_"+to_string(y)+".txt");
			
			if(y==number_of_files-1){
				// loop on the bucket
				for(int file; file<(addresses.size()-(d*y)); file++){
					instream2.open(addresses[file+(d*y)]);
					//length_file= instream2.length();
					while(!instream2.end_of_stream()){
						s= instream2.readln();
						//if not end of the file, write it
						if(s.size()!=0){
							outputstream1.writeln(s);
						}
					}
				}
			}
			else{
				for(int file; file<d; file++){
					instream2.open(addresses[file+(d*y)]);
					while(!instream2.end_of_stream()){
						s= instream2.readln();
						//if not end of the file, write it
						if(s.size()!=0){
							outputstream1.writeln(s);
						}
					}
				
				}
			}
		addresses.push_back("mergedfile"+to_string(x)+"_"+to_string(y)+".txt");
		//supprimer les d ou moins fichiers merge de la luste d'addresses
		outputstream1.close();
		}
		x++;
		

		j++;
	}
}