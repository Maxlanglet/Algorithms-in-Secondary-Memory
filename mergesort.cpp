#include "mergesort.hpp"

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)


bool compare(const string& first, const string& sec, int k){
	//TODO: trouver moyen d'envoyer k ici

	int i=k-1;
	if (tolower(first[i])<tolower(sec[i])) return true;
	else if (tolower(first[i])>tolower(sec[i])) return false;


	return ( first.length() < sec.length() );
}


struct Line
{
    string line;
	char kchar;//ajouter condition sur k ici quelque part
	int column;
	Line(string l, int k):line(l), kchar(line[k]), column(k){}
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
	OutputStream3 outputstream1;


	InputStream2 instream2;
	instream2.open(inputfile.c_str());
	instream2.seek(0);


	list<Line> mylist;
	list<string> addresses;
	list<Line>::iterator it;

	int j=0;


	column=k;
	int l=0;

	//int size = instream2.length(); not necessary because we want lines

	//int nm = ceil(size/M);

	// read the whole file, put in numberoflines/M files and sort them on the k character
	while(!instream2.end_of_stream()){
		addresses.push_back("outputfile"+to_string(j)+".txt");//ca devrait pas être une liste de pointeurs?

		int i =0;

		while(i<M){
			if (!instream2.end_of_stream()){//toujours vérifié
				string temp = instream2.readln();
				l++;
				//cout << temp;
				Line line_to_add = Line(temp, k);
				//cout << line_to_add.kchar << endl;
				mylist.push_back(line_to_add);				
			}
			else{
				i=M;
			}
			i++;
		}
		//instream2.close();

		outputstream1.create("outputfile"+to_string(j)+".txt");

		mylist.sort(LineComparator());
		it = mylist.begin();
	    while(it != mylist.end())
	    {
			string fileline = it->line;
	        outputstream1.writeln(fileline);//toujours probleme, write tout sauf au eof
	        it++;
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
		} 
		for (int i = 0; i < mylist.size(); ++i)//mylist.size()
		{
			//cout << i << endl;
			outputstream1.writeln(it->line);
			++it;
			assert(it != mylist.end());
		}

		*/

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
	instream2.close();
	//TODO: add if j>d
	int x=0;
	string s;
	list<string>::iterator paths;

	InputStream2* lists = (InputStream2*)malloc(sizeof(InputStream2)*j);
	paths = addresses.begin();
    while(paths != addresses.end())
    {
    	s = paths->c_str();//change
		InputStream2 in ;
		in.open(s.c_str());
		in.seek(0);
		lists[x]=in;	
        ++paths;
        x++;
    }

    if(d>j){
    	d=j;
    }

    list<string> lin;//should be size d
    //string* lin; on peut pas pcq on a pas la taille de la ligne

    outputstream1.create("winner.txt");

    for(int i=0; i < d; i++){//init of lin
    	lin.push_back(lists[i].readln());
    	//cout << lists[i].readln();
    }

    int p=0;
    while(p<l){//add remove file is eof 
    	paths = lin.begin();
    	string winner = paths->c_str();
    	int win = 0;
    	paths++;
    	for(int i=1; i<d; i++){
    		if(compare(winner, paths->c_str(), k)){
    			winner = paths->c_str();
    			cout << winner;
    			win = i;
    		}
    		paths++;
    	}
    	outputstream1.writeln(winner);
    	string rep = lists[win].readln();
    	lin.assign(win,rep);
    	p++;
    	cout << p;
    }

	/*
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
		*/
		x++;
		

		j++;
	//}
}