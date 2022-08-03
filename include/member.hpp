#ifndef INCLUDE_MEMBER_HPP_
#define INCLUDE_MEMBER_HPP_

#include <iostream>
#include <string>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <fmt/format.h>
#include <fstream>

#include "person.hpp"


using namespace std;

const int MAXIMUM_BOOKS_BORROW_LIMIT = 3;
const string MAX_BOOK_BORROW_LIMIT_MESSAGE = "Member has alreaday borrowed mamimum books.";

class Member : public Person {
    friend ostream& operator<< (ostream& os,const  Member& rhs);
    friend bool operator== (const Member& lhs, const Member& rhs);
    // declare serialize as a friend for direct access to private data
   template<typename Archive>
   friend void serialize(Archive& archive, Member& record);

    public:
        Member(string mFirstName, string mLastName, string mEmail, string maddress);
        Member(string mFirstName, string mEmail);
        int  borrow_book(long book_id);
        long  return_book(long book_id);
    private:
        vector<long> m_borrowed_book_list;
        
};
 
 // function template serialize is responsible for serializing and 
// deserializing Record objects to/from the specified Archive
template <typename Archive>
void serialize(Archive& archive, Member& record) {
   archive(cereal::make_nvp("m_borrowed_book_list", record.m_borrowed_book_list));
}

#endif