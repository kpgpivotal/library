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



using namespace std;

class Library {
	public:
		Library( string name);
		void launch();

	private:
		string mName;
		int show_menu();

};




#endif /* INCLUDE_LIBRARY_HPP_ */
