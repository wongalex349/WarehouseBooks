// Alex Wong
// Proj 03 Warehouse.cpp
// Thomas Huang
// 4/24/19

#include <iostream>
#include <fstream>
#include "Warehouse.h"
#include <string>
#include "Book.h"

std::istream& operator >> (istream& is, Warehouse& warehouse)
{
   
   while(!is.eof() && warehouse.bookCount < 35)
   {
      
      Book* node = warehouse.head;
      Book* next = new Book();
      is >> *next;
      warehouse.head = next;
      warehouse.head->setNext(node);
      warehouse.bookCount++;
      warehouse.sort_();
   }
   return is;
}

std::ostream& operator << (ostream& os, const Warehouse& warehouse)
{
   Book* node = warehouse.head;
   node = node->getNext();
   while(node != nullptr)
   {
      os << *node << endl;
      node = node->getNext();
      
   }
   return os;

}

   Warehouse::Warehouse()
   {
  
      bookCount = 0;
   }
   Book* Warehouse::find(string isbn) const
   {
      bool found = false;
      Book* currentNode = head;
      while(!found && currentNode != nullptr)
      {
         if(currentNode->getIsbn() == isbn)
         {
            cout << "ISBN: " << isbn << " -- FOUND" << endl;
            cout << *currentNode << endl;
            found = true;
         }
         else 
            currentNode = currentNode->getNext();
      }
      if(currentNode->getIsbn() != isbn)
      {
         cout <<"isbn not found" << endl;
         return nullptr;
      }
      return currentNode;
   }
   void Warehouse::list() const
   {      
         cout << *this;
      
   }

   void Warehouse::sort_()
   {
      bool sorted = false;
      Book* node;
      Book* next;
      Book* current;

      if(head->getNext() != nullptr)
      {
         next = head->getNext();
         if(head->getTitle().compare(next->getTitle()) >0)
         {
            node = next->getNext();
            head->setNext(node);
            next->setNext(head);
            head = next;
         }
         
      
         Book* var = head;
         Book* nextNode = var->getNext();
         while( !sorted && nextNode->getNext() != nullptr)
         {
            current = var->getNext();
            next = current->getNext();

            if(current->getTitle().compare(next->getTitle()) > 0)
            {

               node = next->getNext();
               current->setNext(node);
               next->setNext(current);
               var->setNext(next);

            }
            else
               sorted = true;
            var = current;
            nextNode = current->getNext();
         }
      }

   }
      
   
