#include "book.hpp"


Book::Book( string name,  Author author, int quantity) : mName{name} ,
        mTotalQuantity{quantity} 
{
    mId = ++BOOK_ID;
    mAuthorList.push_back(author);
    mAuthorName = author.getName();
    mBorrowedQuantity = 0;
}

Book::Book( string name,  Author author, Author author2,int quantity): mName{name} ,
        mTotalQuantity{quantity} 
{
    mId = ++BOOK_ID;
    mAuthorList.push_back(author);
    mAuthorName = author.getName();
    mAuthorList.push_back(author2);
    mAuthorName.append(" , ");
    mAuthorName.append(author2.getName());
    mBorrowedQuantity = 0;
}



ostream& operator<< (ostream& os, const Book& rhs){
    os << endl << rhs.mId << "\t" << rhs.mName << "\t" << rhs.mAuthorName << "\t" << rhs.mTotalQuantity << "\t" << rhs.mBorrowedQuantity;
    return os;
}

string Book::getAuthors(){
    string author_names{};
    bool is_first{true};

    for (const Person theauthor : mAuthorList) {
        if ( true == is_first) {
            is_first = false;
        }
        else {
            author_names.append(", ");      
        }

        author_names.append(theauthor.getName());
    }

    return author_names;
}

vector<Author> Book::getAuthorsList(){
    return mAuthorList;
}

bool Book::isAvailable(){
    if ( mBorrowedQuantity < mTotalQuantity ) {
        return true;
    }

    return false;
}