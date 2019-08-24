// Alex Wong
// Thomas Huang
// Proj 03 Book.cpp

#include <iomanip>
#include "Book.h"
#include <fstream>
#include <string>
#include <iostream>
std::istream& operator >> (istream& is, Book& book)
{
   string space = "";
   getline(is,book.title);
   is >> book.authorCount;
   getline(is, space);
   for(int i = 0; i < book.authorCount; i++)
      getline(is,book.authors[i]);
   getline(is,book.publisher);
   is >> book.yearPublish;
   is >> book.hardcover;
   is >> book.price;
   is >> book.isbn;
   is >> book.copies;
   getline(is, space);
   return is;
}

std::ostream& operator << (ostream& os, const Book& book) 
{
   os << setprecision(2) << fixed;
   os << "Title: " << book.title << endl;
   for(int i = 0; i < book.authorCount; i++)
      os << "Author: " << book.authors[i] << endl;
   os << "Publisher: " << book.publisher << endl;
   os << "Year: " << book.yearPublish << endl;
   if(book.hardcover == true)
      os << "Cover: Hardcover" << endl;
   else
      os << "Cover: Paperback " << endl;
   os << "Price: $" << book.price << endl;
   os << "ISBN: " << book.isbn << endl;
   os << "Copies: " << book.copies << endl;
   return os;
}
Book::Book()
{
   
}
Book::Book(string title, string authors[], int authorCount, string publisher,
 short yearPublish, bool hardcover, float price,
 string isbn, long copies)
{
   this->title = title;
   for(int i = 0; i < authorCount; i++)
      this->authors[i] = authors[i];
   this->authorCount = authorCount;
   this->publisher = publisher;
   this->yearPublish = yearPublish;
   this->isbn = isbn;
   this->hardcover = hardcover;
   this->price = price;
   this->copies = copies;
}
void Book::setTitle(string title)
{
   this->title = title;
}

string Book::getTitle()
{
   return title;
}

void Book::setAuthorCount(int authorCount)
{
   this->authorCount = authorCount;
}
int Book::getAuthorCount()
{
   return authorCount;
}
void Book::setPublisher(string publisher)
{
   this->publisher = publisher;
}
string Book::getPublisher()
{
   return publisher;
}
void Book::setIsbn(string isbn)
{
   this->isbn = isbn;
}
string Book::getIsbn() const
{
   return isbn;
}
void Book::setHardcover(bool hardcover)
{
   this->hardcover = hardcover;
}
bool Book::getHardcover()
{
   return hardcover;
}
void Book::setYearPublish(short yearPublish)
{
   this->yearPublish = yearPublish;
}
short Book::getYearPublish()
{
   return yearPublish;
}
void Book::setCopies(long copies)
{
   this->copies = copies;
}
long Book::getCopies()
{
   return copies;
}
void Book::setPrice(float price)
{
   this->price = price;
}
float Book::getPrice()
{
   return price;
}

Book* Book::getNext() const
{
   return next;
}

void Book::setNext(Book* next)
{
   this->next = next;
}
