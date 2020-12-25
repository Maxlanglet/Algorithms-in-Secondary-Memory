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
	//int column;
	int index;
	int toseek;
	Line(string l, int k, int ind, int ts){
		line=l;
		if(k>l.length()){
			kchar=(l.length()-1);
		}
		else{
			kchar=line[k-1];
		}
		index=ind;
		toseek=ts;
		//column=k;
	}
	Line(string l, int k){
		line=l;
		if(k>l.length()){
			kchar=(l.length()-1);
		}
		else{
			kchar=line[k-1];
		}
		index=0;
		toseek=0;
		//column=k;
	}
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

void mergesort::extsort(string inputfile, int k, int M, float d){
	//tester savoir quel outputstream utiliser ici, pour le moment outputstream1
	OutputStream3 outputstream1;


	InputStream2 instream2;
	instream2.open(inputfile.c_str());
	instream2.seek(0);


	vector<Line> mylist;
	vector<string> addresses;
	vector<Line>::iterator it;

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

		sort(mylist.begin(),mylist.end(),LineComparator());
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
		} */
		for (int i = 0; i < mylist.size(); ++i)//mylist.size()
		{
			//cout << i << endl;
			outputstream1.writeln(it->line);
			++it;
			assert(it != mylist.end());
		}
		outputstream1.close();
		

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
	/*
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
	
*/

	

	//merge procedure until there is only 1 file left in addresses
	while(addresses.size()!=1){
		// number of files in addresses in this pass (cant use j because it will change at each pass)
		int number_of_files = ceil(addresses.size()/d);
		cout << addresses.size()/d << endl;
		
		int addr_pass_size = addresses.size();

		// merge d files, x is the pass we are at, y is the number of the bucket of d file in that pass
		for(int y=0; y<number_of_files; y++){
			
			

			//in case we are at the end of the list of files to merge and there is less than d files
			if(y==number_of_files-1){
				cout << " creating the merging file" << endl;
				//creates the file merging d or less files
				outputstream1.create("mergedfile"+to_string(x)+"_"+to_string(y)+".txt");
			
				cout << "number of file to merge < d" << endl;
				// the number of files left for the last bucket is
				// the initial size of addresse of the pass minus d* the number of passes we did
				int leftover = addr_pass_size-(d*y);
				//adds the first line in the list of line
				for(int file=0; file<(leftover); file++){
					cout << " trying to open " << (addresses[file]).c_str() << endl;
					instream2.open((addresses[file]).c_str());
					s= instream2.readln();
					mylist.push_back(Line(s,k,file,s.size()));
					instream2.close();
				}

				// while the list of lines is not empty
				while(mylist.size()!=0){
					cout << " size of mylist " << mylist.size() << endl;
					cout << " size of addr " << addresses.size() << endl;
					sort(mylist.begin(),mylist.end(),LineComparator());

					//write the first line in the file
					outputstream1.writeln((mylist[0].line).c_str());
					cout << " index of WINNER " <<mylist[0].index << endl;
					cout << " trying to open the WINNER " << (addresses[(mylist[0].index)]).c_str() << endl;
					//opens the file of the winner using the index saved in the line structure
					instream2.open((addresses[(mylist[0].index)]).c_str());

					//reads the next line in the file
					//on va devoir faire un LSEEK!!
					instream2.seek(mylist[0].toseek);
					//-> attribut en plus dans la structure Line sauvant là où on en est dans le fichier
					s= instream2.readln();

					//if we are not at the end of that file
					if(s.size()!=0){
						//adds the line at the end of mylist so the index is the size of it
						mylist.push_back(Line(s,k,mylist[0].index,(mylist[0].toseek)+(s.size())));
						instream2.close();
						//erases the winner from the list of lines
						mylist.erase(mylist.begin());

					}
					//if we are at the end of the file
					else{
						instream2.close();

						//removes the intermediary file
						if (remove((addresses[(mylist[0].index)]).c_str()) != 0)
							perror("File deletion failed");

						//suppress	the file in addresses				
						addresses.erase(addresses.begin() + (mylist[0]).index);
						
						//updates the index of the lines in mylist
						for (int j =0; j < mylist.size(); j++) {
							cout << " updating the index of mylist "<< endl;
							if(mylist[j].index>mylist[0].index)
								mylist[j].index--;
							}
					
						//erases the winner from the list of lines
						mylist.erase(mylist.begin());
					}
				}
				cout << " adding the file " << "mergedfile"+to_string(x)+"_"+to_string(y)+".txt" << endl;
				//adds the new merged file to the list of addresses
				addresses.push_back("mergedfile"+to_string(x)+"_"+to_string(y)+".txt");
				//closes the stream of that merged file
				outputstream1.close();
			}


			//there are still at least d files left
			else{
				cout << " creating the merging file" << endl;
				//creates the file merging d or less files
				outputstream1.create("mergedfile"+to_string(x)+"_"+to_string(y)+".txt");
			
				cout << " number of file to merge >= d" << endl;
				//adds the first line in the list of lines
				for(int file; file<d; file++){
					cout << " trying to open " << (addresses[file]).c_str() << endl;
					instream2.open((addresses[file+(d*y)]).c_str());
					s= instream2.readln();
					mylist.push_back(Line(s,k,file,s.size()));
					instream2.close();
				}

				
				// while the list of lines is not empty
				while(mylist.size()!=0){
					cout << " size of mylist " << mylist.size() << endl;
					cout << " size of addr " << addresses.size() << endl;

					sort(mylist.begin(),mylist.end(),LineComparator());

					//write the first line in the file
					outputstream1.writeln((mylist[0].line).c_str());
					cout << " index of WINNER " <<mylist[0].index << endl;
					cout << " trying to open the WINNER " << (addresses[(mylist[0].index)]).c_str() << endl;
					//opens the file of the winner using the index saved in the line structure
					instream2.open((addresses[(mylist[0].index)]).c_str());

					//reads the next line in the file
					//on va devoir faire un LSEEK!!
					instream2.seek(mylist[0].toseek);
					//-> attribut en plus dans la structure Line sauvant là où on en est dans le fichier
					s= instream2.readln();

					//if we are not at the end of that file
					if(s.size()!=0){
						//adds the line at the end of mylist so the index is the size of it
						mylist.push_back(Line(s,k,mylist[0].index,(mylist[0].toseek)+(s.size())));
						instream2.close();
						//erases the winner from the list of lines
						mylist.erase(mylist.begin());

					}
					//if we are at the end of the file
					else{
						instream2.close();

						//removes the intermediary file
						if (remove((addresses[(mylist[0].index)]).c_str()) != 0)
							perror("File deletion failed");

						//suppress	the file in addresses				
						addresses.erase(addresses.begin() + (mylist[0]).index);
						
						//updates the index of the lines in mylist
						cout << " updating the index of mylist "<< endl;
						for (int j =  0; j < mylist.size(); j++) { 
							if(mylist[j].index>mylist[0].index)
								mylist[j].index--;
							}
					
						//erases the winner from the list of lines
						mylist.erase(mylist.begin());
					}
				}
				cout << " adding the file " << "mergedfile"+to_string(x)+"_"+to_string(y)+".txt" << endl;
				//adds the new merged file to the list of addresses
				addresses.push_back("mergedfile"+to_string(x)+"_"+to_string(y)+".txt");
				//closes the stream of that merged file
				outputstream1.close();
			}
	
		}

		//we are going to another pass so increment x	
		x++;

		//j++;
	}
}