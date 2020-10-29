#include "InputStream4.hpp"
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>

#define BUF_SIZE 256

//Input stream for the memory mapping process, creates mapped handle 
InputStream4::InputStream4(string filename){
	path = filename;
	LPCTSTR pBuf;	//pointer to constant TCHAR string
	HANDLE hMapFile;  //generic identifier to represent something, generally never used directly but rather gets 
					 //passed to the function that uses it (here CreateMappingFile)
	//HANDLE hMapFile; 
	//TCHAR covers both multibyte and unicode, TEXT defines a string as unicode
	//"Global\" allows processes to communicate with each other even if they are in different terminal server sessions.
	//This requires that the first process must have the SeCreateGlobalPrivilege privilege. (run VS as admin)
	TCHAR szName[]=TEXT("Global\\MyFileMappingObjectGhita"); 
	TCHAR szMsg[]=TEXT("Message from first process tested by ghita.");
	
   	this->hMapFile = CreateFileMapping( 		  
                 INVALID_HANDLE_VALUE,    // use paging file
                 NULL,                    // default security
                 PAGE_READWRITE,          // read/write access
                 0,                       // maximum object size (high-order DWORD) 
				 						  // means maximum size can be represented with just a DWORD (32bits)
                 BUF_SIZE,                // maximum object size (low-order DWORD)
                 szName);                 // name of mapping object

   if (this->hMapFile == NULL)
   {
      _tprintf(TEXT("Could not create file mapping object (%d).\n"),
             GetLastError());
      exit(1);
   }
}

InputStream4::~InputStream4(){}

void InputStream4::open(){ //we need to stock the entire file input in a mapped region of memory 
	//MapViewOfFile creates a view of the file in the process address space, return a pointer to the file view
   // returns the starting address of the mapped view !!
   this->pBuf = (LPTSTR) MapViewOfFile(this->hMapFile,   // handle to map object
                        FILE_MAP_ALL_ACCESS, // read/write permission
                        0,
                        0,
                        BUF_SIZE);

   if (pBuf == NULL)
   {
      _tprintf(TEXT("1Could not map view of file (%d).\n"),
             GetLastError());
	  CloseHandle(hMapFile);
      exit(1);
   }
   std::cout<< "here so far \n";
	TCHAR szMsg[]=TEXT("Message from first process tested by ghita.");
	LPCTSTR bu=this->pBuf;
	CopyMemory((PVOID)bu, szMsg, (_tcslen(szMsg) * sizeof(TCHAR)));
	std::cout<< "done\n";
   UnmapViewOfFile(pBuf);
   
	// open the file
	/*ifstream file (path);
	if(!file.is_open()){
		cout << "Impossible to open the file" << endl;
	}*/
}

//caractère par caractère
//peut etre faut il utiliser fonction read() de unistd mais pas reussis a faire fonctionner
//peut etre file.read(c,1)
void InputStream4::readln(){
	if(this->hMapFile==NULL){std::cout<<"nulle looser";}
	this->hMapFile = OpenFileMapping(
                   FILE_MAP_ALL_ACCESS,   // read/write access
                   FALSE,                 // do not inherit the name
                   TEXT("Global\\MyFileMappingObjectGhita"));               // name of mapping object

   if (this->hMapFile == NULL)
   {
      _tprintf(TEXT("Could not open file mapping object (%d).\n"),
             GetLastError());
      exit(1);
   }

   pBuf = (LPTSTR) MapViewOfFile(hMapFile, // handle to map object
               FILE_MAP_ALL_ACCESS,  // read/write permission
               0,
               0,
               BUF_SIZE);

   if (pBuf == NULL)
   {
      _tprintf(TEXT("2Could not map view of file (%d).\n"),
             GetLastError());

      CloseHandle(hMapFile);

      exit(1);
   }

   MessageBox(NULL, pBuf, TEXT("Process2"), MB_OK);

   UnmapViewOfFile(pBuf);

   CloseHandle(hMapFile); //put it in destructor ?
	/*if (file){
		string line;
		char c;
		while (file.get(c))
		{
			line += c;
			if (c == '\n' || c == '\r'){
				cout << line;
				line="";
			}
		}
	}
	else{
		cout << "File is not open" << endl;
	}*/
}

void InputStream4::seek(int pos){
	file.seekg(pos);
}

bool InputStream4::end_of_stream(){
	if(file.eof()){
		return true;
	}
	else{
		return false;
	}
}

void InputStream4::close(){
	file.close();
}


