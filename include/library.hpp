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
#include "utils.hpp"
#include "person.hpp"
//#include "librarian.hpp"
#include "book.hpp"
#include "member.hpp"

using namespace std;

const int 	EXIT_MENU_CHOICE = 10;
const string SEARCH_BOOKS_BY_PREFIX_PROMPT = "Please enter the books prefix to search ";

bool compare_by_id(Book& b1, Book& b2);
class Library {
	public:
		Library(string name);
		Library( Library& rhs ) = delete;
		Library operator= ( Library& rhs ) = delete;
		void launch();
		int add_book();

	private:
		string mName;
		int show_menu();
		int process_user_choice( int choice);
		//Librarian*  mpLibrarian;
		vector<Book> mBookList;
		vector<Member> mMemberList;
		//std::unordered_set<Book>* mpBookSet =nullptr;
		int print_library_by_bookname();
		int print_library_by_id();
		int add_user();
		int search_books_prefix();
		int check_add_new_book(Book& theBbook);
		int print_members();
		int add_user_to_list(Member new_member);


};




#endif /* INCLUDE_LIBRARY_HPP_ */
