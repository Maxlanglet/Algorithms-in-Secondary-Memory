#include "mergesort.hpp"

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)


//Defining structure Line
struct Line
{
    vector<string> word;
	string line;
	string kchar;
	string index;
	int toseek;
	Line(string l, vector<string> w, int k, string ind, int ts){
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
		index="";
		toseek=0;
	}
};

//Comparator for lexicographical order
auto comparator = [] (const Line & line1, const Line & line2)
{
    if(line1.kchar == line2.kchar)
            return line1.kchar > line2.kchar;
        return line1.kchar > line2.kchar;
};


//splits the line into separate colomns
vector<string> split(string line_read){


    string strTempString;
    vector<int> splitIndices;
    vector<string> vector_words;
    int nLineSize = line_read.size();

    // find indices
    splitIndices.push_back(-1);          
    for(int i = 0; i < nLineSize; i++){
        if(line_read[i] == ',')
            splitIndices.push_back(i);
    }

    // fill split lines
    for(int i = 0; i <int(splitIndices.size()); i++){
        strTempString = line_read.substr(splitIndices[i]+1, (splitIndices[i+1] - (splitIndices[i]+1) ));
        vector_words.push_back(strTempString);
    }
    return vector_words;
}


mergesort::mergesort(){}


mergesort::~mergesort(){}

void mergesort::extsort(string inputfile, int k, int M, float d){
	OutputStream2 outputstream1;


	InputStream2 instream2;
	instream2.open(inputfile.c_str());
	instream2.seek(0);

	priority_queue<Line, vector<Line>, decltype(comparator)> mylist(comparator);
	vector<string> addresses;
	vector<Line>::iterator it;

	int j=0;


	column=k;
	int l=0;



	// read the whole file, put in numberoflines/M files and sort them on the k character
	while(!instream2.end_of_stream()){
		addresses.push_back("outputfile"+to_string(j)+".txt");

		int i =0;
		while(i<M){
			if (!instream2.end_of_stream()){
				string temp = instream2.readln();
				vector <string> line_words;
				l++;
				line_words=split(temp);
				
				Line line_to_add = Line(temp,line_words, k);
				mylist.push(line_to_add);
				line_words.clear();				
			}
			else{
				i=M;
			}
			i++;
		}

		outputstream1.create(("outputfile"+to_string(j)+".txt").c_str());
		while(!mylist.empty())   {
	        outputstream1.writeln( mylist.top().line);
			mylist.pop();
	        
	    }
		j++;
	
		outputstream1.close();

	}

	
	instream2.close();

	int x=0;
	string s;

	

	//merge procedure until there is only 1 file left in addresses
	while(addresses.size()!=1){
		// number of files in addresses in this pass (cant use j because it will change at each pass)
		int number_of_files = ceil(addresses.size()/d);

		
		int addr_pass_size = addresses.size();
	
		// merge d files, x is the pass we are at, y is the number of the bucket of d file in that pass
		for(int y=0; y<number_of_files; y++){
			
			//in case we are at the end of the list of files to merge and there is less than d files
			if(y==number_of_files-1){
				//creates the file merging d or less files
				outputstream1.create(("mergedfile"+to_string(x)+"_"+to_string(y)+".txt").c_str());
				// the number of files left for the last bucket is
				// the initial size of addresse of the pass minus d* the number of passes we did
				int leftover = addr_pass_size-(d*y);

				//adds the first line in the list of line
				for(int file=0; file<(leftover); file++){
					instream2.open((addresses[file]).c_str());
					s= instream2.readln();
					vector <string> line_words;
					line_words=split(s);
					mylist.push(Line(s,line_words,k,addresses[file],s.size()));
					line_words.clear();
					instream2.close();
				}

				// while the list of lines is not empty
				while(!mylist.empty()){

					//write the first line in the file
					outputstream1.writeln((mylist.top().line).c_str());

					//opens the file of the winner using the index saved in the line structure
					instream2.open((mylist.top().index).c_str());

					//reads the next line in the file
					instream2.seek(mylist.top().toseek);
					s= instream2.readln();

					//if we are not at the end of that file
					if(s.size()!=0){
						//adds the line at the end of mylist so the index is the size of it
						vector <string> line_words;
						line_words=split(s);
						mylist.push(Line(s,line_words,k,mylist.top().index,(mylist.top().toseek)+(s.size())));
						line_words.clear();
						instream2.close();
						//erases the winner from the list of lines
						mylist.pop();

					}
					//if we are at the end of the file
					else{
						instream2.close();
						//removes the intermediary file
						if (remove((mylist.top().index).c_str()) != 0)
							perror("File deletion failed");

						addresses.erase(std::remove(addresses.begin(), addresses.end(), mylist.top().index), addresses.end());
						
						
						mylist.pop();
					}
				}
				
				//adds the new merged file to the list of addresses
				addresses.push_back("mergedfile"+to_string(x)+"_"+to_string(y)+".txt");
				//closes the stream of that merged file
				outputstream1.close();
			}


			//there are still at least d files left
			else{

				//creates the file merging d files
				outputstream1.create(("mergedfile"+to_string(x)+"_"+to_string(y)+".txt").c_str());

				//adds the first line in the list of lines
				for(int file=0; file<d; file++){
					instream2.open((addresses[file]).c_str());
					s= instream2.readln();
					vector <string> line_words;
					line_words=split(s);
					mylist.push(Line(s,line_words,k,addresses[file],s.size()));
					line_words.clear();
					instream2.close();
				}

				
				// while the list of lines is not empty
				while(!mylist.empty()){
					//write the first line in the file
					outputstream1.writeln((mylist.top().line).c_str());

					//opens the file of the winner using the index saved in the line structure
					instream2.open((mylist.top().index).c_str());

					//reads the next line in the file
					instream2.seek(mylist.top().toseek);
					s= instream2.readln();

					//if we are not at the end of that file
					if(s.size()!=0){
						//adds the line at the end of mylist so the index is the size of it
						vector <string> line_words;
						line_words=split(s);
						mylist.push(Line(s,line_words,k,mylist.top().index,(mylist.top().toseek)+(s.size())));
						line_words.clear();
						instream2.close();
						//erases the winner from the list of lines
						mylist.pop();

					}
					//if we are at the end of the file
					else{
						instream2.close();
						//removes the intermediary file
						if (remove((mylist.top().index).c_str()) != 0)
							perror("File deletion failed");

						addresses.erase(std::remove(addresses.begin(), addresses.end(), mylist.top().index), addresses.end());
						
						
						//erases the winner from the list of lines

						mylist.pop();
					}
				}
				//adds the new merged file to the list of addresses
				addresses.push_back("mergedfile"+to_string(x)+"_"+to_string(y)+".txt");
				//closes the stream of that merged file
				outputstream1.close();
			}
	
		}
		//we are going to do another pass so increment x	
		x++;
	}
}