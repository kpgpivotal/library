#ifndef INCLUDE_BOOK_HPP_
#define INCLUDE_BOOK_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <fmt/format.h>
#include <fstream>

#include "author.hpp"
#include "member.hpp"
#include "utils.hpp"



using namespace std;
static long BOOK_ID = 0;

class Book {
    friend ostream& operator<< (ostream& os, const Book& rhs);
       // declare serialize as a friend for direct access to private data
   template<typename Archive>
   friend void serialize(Archive& archive, Book& record);
    
    public:
        Book();
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
 
// function template serialize is responsible for serializing and 
// deserializing Record objects to/from the specified Archive
template <typename Archive>
void serialize(Archive& archive, Book& record) {
   archive(cereal::make_nvp("mId", record.mId),
    cereal::make_nvp("mName", record.mName),
      cereal::make_nvp("mAuthorName", record.mAuthorName),
      cereal::make_nvp("mTotalQuantity", record.mTotalQuantity),
      cereal::make_nvp("mBorrowedQuantity", record.mBorrowedQuantity),
      cereal::make_nvp("mAuthorList", record.mAuthorList),
      cereal::make_nvp("mBorrowedMemberList", record.mBorrowedMemberList));
}

#endif