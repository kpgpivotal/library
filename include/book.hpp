#ifndef INCLUDE_BOOK_HPP_
#define INCLUDE_BOOK_HPP_

#include <iostream>
#include <string>
#include <vector>

#include "author.hpp"
#include "member.hpp"
#include "utils.hpp"



using namespace std;
static long BOOK_ID = 0;

class Book {
    friend ostream& operator<< (ostream& os, const Book& rhs);
    
    public:
        //Book();
        Book( string name,  Author author, int quantity);
        Book( string name, Author author, Author author2, int quantity);
        bool operator<(const Book& rhs);
        bool operator==(const Book& rhs);
        Book& operator+=(const Book& rhs);
        string getAuthors();
        bool isAvailable();
        vector<Author> getAuthorsList();
        int borrow_book(Member member);
        Book* return_book(Member member);
        bool is_already_borrowed_by_member(Member member);
        string getName()const;
        long getId() const;
        string get_borrowers_names()const;



    private:
        long mId;
        string mName;
        string mAuthorName;
        int mTotalQuantity;
        int mBorrowedQuantity;
        vector<Author> mAuthorList;
        vector<Member> mBorrowedMemberList;

};
 
#endif