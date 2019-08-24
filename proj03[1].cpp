// Alex Wong
// CS 2560
// Project3
// Thomas Huang

#include <iostream>
#include <string>
#include <cstring>
#include "Warehouse.h"
#include <fstream>
#include "Book.h"

using namespace std;

int main(int argc, char* argv[])
{
   
   Book* book = new Book();
   Warehouse* warehouse= new Warehouse();
   ifstream inputFile;
   inputFile.open(argv[1]);
   if(inputFile.fail())
   {
      cout << "input file not found" << endl;
      return -1;
   }
   inputFile >> *warehouse;
   if(argc < 3 || !(!strcmp(argv[2], "find") || !strcmp(argv[2], "list") ))
   {
      cout << "./proj01 <input file> find <isbn>" << endl;
      cout << " ./proj01 <input file> list" << endl;
      return -1;
   }
   if(argc ==1)
   {
      cout << "./proj01 <input file> find <isbn>" << endl;
      cout << " ./proj01 <input file> list" << endl;
      return -1;
   }

   else if(!strcmp(argv[2], "list"))
   {
      warehouse->list();
   }
   else if(!strcmp(argv[2], "find"))
   {
      warehouse->find(argv[3]);
   }
   delete warehouse;
   delete book;
   inputFile.close();
   return 0;





}
