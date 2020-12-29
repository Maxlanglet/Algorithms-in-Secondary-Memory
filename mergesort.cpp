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
    vector<string> word;
	string line;
	string kchar;//ajouter condition sur k ici quelque part
	//int column;
	int index;
	int toseek;
	Line(string l, vector<string> w, int k, int ind, int ts){
		word=w;
		line=l;
		if(k>word.size()){
			kchar=word[word.size()-1];

		}
		else{
			//takes the first letter of the word in the kst column
			kchar=word[k-1];
		}
		index=ind;
		toseek=ts;
	}
	Line(string l, vector<string> w, int k){
		word=w;
		line=l;
		if(k>word.size()){
			kchar=word[word.size()-1];
		}
		else{
			//takes the first letter of the word in the kst column
			kchar=word[k-1];
		}
		index=0;
		toseek=0;
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

vector<string> split(string line_read){
	/*string delim=",";
    vector<string> vector_words;
    if (!line_read.empty()) {
        string::size_type start = 0;
        do {
            size_t x = line_read.find(delim, start);
			cout << "found delim at "<< int(x) << endl;
            if (x == string::npos)
				cout << "go out"<< endl;
                break;
			cout << "in SPLIT, adding the word"<< line_read.substr(start, x-start)<< endl;
            vector_words.push_back(line_read.substr(start, x-start));
            start += x + delim.size();
        }
        while (true);
		cout << "in SPLIT PUSHBACK"<<line_read.substr(start) << endl;
        vector_words.push_back(line_read.substr(start));            
    }*/

    string strTempString;
    vector<int> splitIndices;
    vector<string> vector_words;
    int nLineSize = line_read.size();

    // find indices
    splitIndices.push_back(-1);
    /*if(nLineSize!=0 && line_read[0]==','){
         vector_words.push_back(line_read.substr(0,1));
         splitIndices[0]=0;
    } */            
    for(int i = 0; i < nLineSize; i++){
        if(line_read[i] == ',')
            splitIndices.push_back(i);
    }

    // fill split lines
    for(int i = 0; i <int(splitIndices.size()); i++){
        strTempString = line_read.substr(splitIndices[i]+1, (splitIndices[i+1] - (splitIndices[i]+1) ));
		//cout << "word is " << strTempString << endl;
        vector_words.push_back(strTempString);
    }
    return vector_words;
}

mergesort::mergesort(){}


mergesort::~mergesort(){}

void mergesort::extsort(string inputfile, int k, int M, float d){
	//tester savoir quel outputstream utiliser ici, pour le moment outputstream1
	OutputStream2 outputstream1;


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
		//cout << "opening the file and getting the line"<<endl;
		while(i<M){
			if (!instream2.end_of_stream()){//toujours vérifié
				string temp = instream2.readln();
				vector <string> line_words;
				l++;
				//cout << temp;
				line_words=split(temp);
				
				Line line_to_add = Line(temp,line_words, k);
				//cout <<"the k word is " <<line_to_add.kchar << endl;
				mylist.push_back(line_to_add);
				line_words.clear();				
			}
			else{
				i=M;
			}
			i++;
		}
		//instream2.close();

		outputstream1.create(("outputfile"+to_string(j)+".txt").c_str());

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
		


		for (int i = 0; i < mylist.size(); ++i)//mylist.size()
		{
			//cout << i << endl;
			outputstream1.writeln(it->line);
			++it;
			assert(it != mylist.end());
		}
		outputstream1.close();

	}

	
	instream2.close();
	//TODO: add if j>d
	int x=0;
	string s;

	

	//merge procedure until there is only 1 file left in addresses
	while(addresses.size()!=1){
		// number of files in addresses in this pass (cant use j because it will change at each pass)
		int number_of_files = ceil(addresses.size()/d);
		//cout << addresses.size()/d << endl;
		
		int addr_pass_size = addresses.size();

		// merge d files, x is the pass we are at, y is the number of the bucket of d file in that pass
		for(int y=0; y<number_of_files; y++){
			
			

			//in case we are at the end of the list of files to merge and there is less than d files
			if(y==number_of_files-1){
				//cout << " creating the merging file" << endl;
				//creates the file merging d or less files
				outputstream1.create(("mergedfile"+to_string(x)+"_"+to_string(y)+".txt").c_str());
			
				//cout << "number of file to merge < d" << endl;
				// the number of files left for the last bucket is
				// the initial size of addresse of the pass minus d* the number of passes we did
				int leftover = addr_pass_size-(d*y);
				//adds the first line in the list of line
				for(int file=0; file<(leftover); file++){
					//cout << " trying to open " << (addresses[file]).c_str() << endl;
					instream2.open((addresses[file]).c_str());
					s= instream2.readln();
					vector <string> line_words;
					line_words=split(s);
					mylist.push_back(Line(s,line_words,k,file,s.size()));
					line_words.clear();
					instream2.close();
				}

				// while the list of lines is not empty
				while(mylist.size()!=0){
					//cout << " size of mylist " << mylist.size() << endl;
					//cout << " size of addr " << addresses.size() << endl;
					sort(mylist.begin(),mylist.end(),LineComparator());

					//write the first line in the file
					outputstream1.writeln((mylist[0].line).c_str());
					//cout << " index of WINNER " <<mylist[0].index << endl;
					//cout << " trying to open the WINNER " << (addresses[(mylist[0].index)]).c_str() << endl;
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
						vector <string> line_words;
						line_words=split(s);
						mylist.push_back(Line(s,line_words,k,mylist[0].index,(mylist[0].toseek)+(s.size())));
						line_words.clear();
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
							//cout << " updating the index of mylist "<< endl;
							if(mylist[j].index>mylist[0].index)
								mylist[j].index--;
							}
					
						//erases the winner from the list of lines
						mylist.erase(mylist.begin());
					}
				}
				//cout << " adding the file " << "mergedfile"+to_string(x)+"_"+to_string(y)+".txt" << endl;
				//adds the new merged file to the list of addresses
				addresses.push_back("mergedfile"+to_string(x)+"_"+to_string(y)+".txt");
				//closes the stream of that merged file
				outputstream1.close();
			}


			//there are still at least d files left
			else{
				//cout << " creating the merging file" << endl;
				//creates the file merging d or less files
				outputstream1.create(("mergedfile"+to_string(x)+"_"+to_string(y)+".txt").c_str());
			
				//cout << " number of file to merge >= d" << endl;
				//adds the first line in the list of lines
				for(int file; file<d; file++){
					//cout << " trying to open " << (addresses[file]).c_str() << endl;
					instream2.open((addresses[file+(d*y)]).c_str());
					s= instream2.readln();
					vector <string> line_words;
					line_words=split(s);
					mylist.push_back(Line(s,line_words,k,file,s.size()));
					line_words.clear();
					instream2.close();
				}

				
				// while the list of lines is not empty
				while(mylist.size()!=0){
					sort(mylist.begin(),mylist.end(),LineComparator());

					//write the first line in the file
					outputstream1.writeln((mylist[0].line).c_str());

					//opens the file of the winner using the index saved in the line structure
					instream2.open((addresses[(mylist[0].index)]).c_str());

					//reads the next line in the file
					instream2.seek(mylist[0].toseek);
					s= instream2.readln();

					//if we are not at the end of that file
					if(s.size()!=0){
						//adds the line at the end of mylist so the index is the size of it
						vector <string> line_words;
						line_words=split(s);
						mylist.push_back(Line(s,line_words,k,mylist[0].index,(mylist[0].toseek)+(s.size())));
						line_words.clear();
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
						//cout << " updating the index of mylist "<< endl;
						for (int j =  0; j < mylist.size(); j++) { 
							if(mylist[j].index>mylist[0].index)
								mylist[j].index--;
							}
					
						//erases the winner from the list of lines
						mylist.erase(mylist.begin());
					}
				}
				//cout << " adding the file " << "mergedfile"+to_string(x)+"_"+to_string(y)+".txt" << endl;
				//adds the new merged file to the list of addresses
				addresses.push_back("mergedfile"+to_string(x)+"_"+to_string(y)+".txt");
				//closes the stream of that merged file
				outputstream1.close();
			}
	
		}
		//we are going to another pass so increment x	
		x++;
	}
}