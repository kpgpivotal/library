#ifndef INCLUDE_BOOK_HPP_
#define INCLUDE_BOOK_HPP_

#include <iostream>
#include <string>
#include <vector>

#include "author.hpp"



using namespace std;
static long BOOK_ID = 0;

class Book {
    friend ostream& operator<< (ostream& os, const Book& rhs);
    public:
        Book( string name,  Author author, int quantity);
        Book( string name, Author author, Author author2, int quantity);
        string getAuthors();
        bool isAvailable();
        vector<Author> getAuthorsList();


    private:
        long mId;
        string mName;
        string mAuthorName;
        int mTotalQuantity;
        int mBorrowedQuantity;
        vector<Author> mAuthorList;

};
 
#endif