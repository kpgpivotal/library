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
#include "utils.hpp"
#include "person.hpp"
#include "librarian.hpp"

using namespace std;

const int 	EXIT_MENU_CHOICE = 10;

class Library {
	public:
		Library( string name);
		Library( Library& rhs ) = delete;
		Library operator= ( Library& rhs ) = delete;
		void launch();
		int add_book();

	private:
		string mName;
		int show_menu();
		int process_user_choice( int choice);
		Librarian*  mpLibrarian;

};




#endif /* INCLUDE_LIBRARY_HPP_ */
