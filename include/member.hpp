#ifndef INCLUDE_MEMBER_HPP_
#define INCLUDE_MEMBER_HPP_

#include <iostream>
#include <string>

#include "person.hpp"


using namespace std;

const int MAXIMUM_BOOKS_BORROW_LIMIT = 3;
const string MAX_BOOK_BORROW_LIMIT_MESSAGE = "Member has alreaday borrowed mamimum books.";

class Member : public Person {
    friend ostream& operator<< (ostream& os,const  Member& rhs);
    friend bool operator== (const Member& lhs, const Member& rhs);

    public:
        Member(string mFirstName, string mLastName, string mEmail, string maddress);
        Member(string mFirstName, string mEmail);
        int  borrow_book(long book_id);
        long  return_book(long book_id);




    private:
        vector<long> m_borrowed_book_list;
        
        

};
 
#endif