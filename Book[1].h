// @file Book.h

#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>

using namespace std;

class Book {

 /**
 * @param is the input stream
 * @param book the book object to be filled
 * @return the input stream
 */
    friend istream& operator >> (istream& is, Book& book);

 /**
 * @param os the output stream
 * @param book the book object reference * @return the output stream
 */
    friend ostream& operator << (ostream& os, const Book& book);

 public:
    static const int MAX_AUTHORS = 35;

    Book();

   Book(string title, string authors[], int authorCount, string publisher,
    short yearPublish, bool hardcover, float price,
    string isbn, long copies);

    void setTitle(string title);
    string getTitle();
    void setAuthorCount(int authorCount);
    int getAuthorCount();
    void setPublisher(string publisher);
    string getPublisher();
    void setYearPublish(short yearPublish);
    short getYearPublish();
    void setHardcover(bool hardcover);
    bool getHardcover();
    void setPrice(float price);
    float getPrice();
    void setIsbn(string isbn);
    string getIsbn() const;
    void setCopies(long copies);
    long getCopies();




    /** add all relevant setter and getter methods **/

    Book* getNext() const;

    void setNext(Book* next);

 private:
    string title;

    string authors[Book::MAX_AUTHORS];
    int authorCount;
    string publisher;
    short yearPublish;
    bool hardcover;
    float price;
    string isbn;
    long copies;

    /** add all attributes **/

    Book* next;

};
#endif /* BOOK_H */
