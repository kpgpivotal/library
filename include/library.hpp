/*
 * library.hpp
 *
 *  Created on: Jul 18, 2022
 *      Author: kishore
 */

#ifndef INCLUDE_LIBRARY_HPP_
#define INCLUDE_LIBRARY_HPP_

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <unordered_set>
#include <memory>
#include <cstddef> 
#include <iomanip>
#include <fstream>


#include <boost/archive/tmpdir.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/assume_abstract.hpp>

#include "utils.hpp"
#include "book.hpp"
#include "member.hpp"


using namespace std;
using namespace boost::archive;

const int 	EXIT_MENU_CHOICE = 10;
const string DATA_FILE_NAME = "library.json";
const string SEARCH_BOOKS_BY_PREFIX_PROMPT = "Please enter the books prefix to search ";
const string EMAIL_INPUT_PROMPT = "Please enter email id of the the user ";
const string EMPTY_MEMBER_LIST_MESSAGE = "Memeber list is empty";
const string MEMBER_NOT_FOUND_WITH_GIVEN_EMAIL = "Member with given email id not found!";
const string BOOK_ID_INPUT_PROMPT = "Please enter Book's id : ";
const string BOOK_LIST_EMPTY_MESSAGE = "Book list is empty";

bool compare_by_id(Book& b1, Book& b2);
class Library {
	template<typename Archive>
   friend void serialize(Archive& archive, Library& record);

	public:
		Library();
		Library(string name);
		Library( Library& rhs ) = delete;
		Library operator= ( Library& rhs ) = delete;
		void launch();
		int add_book();

	private:
		string mName;
		int show_menu();
		int process_user_choice( int choice);
		vector<Book> mBookList;
		vector<Member> mMemberList;
		int print_library_by_bookname();
		int print_library_by_id();
		int add_user();
		int search_books_prefix();
		int check_add_new_book(Book& theBbook);
		int print_members();
		int add_user_to_list(Member new_member);
		int borrow_book();
		int return_book();
		Member *get_member_by_email(string email);
		Book *get_book_by_id(long id);
		int borrowers_info();
		int save_data_file();
		int read_data_file();


	// function template serialize is responsible for serializing and 
	// deserializing Record objects to/from the specified Archive
	template <typename Archive>
	void serialize(Archive& archive, Library& record) {
	archive(cereal::make_nvp("mName", record.mName),
		cereal::make_nvp("mBookList", record.mBookList),
		cereal::make_nvp("mMemberList", record.mMemberList));
	}


};

#endif /* INCLUDE_LIBRARY_HPP_ */
