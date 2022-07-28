/*
 * main.cpp
 *
 *  Created on: Jul 18, 2022
 *      Author: kishore
 */

#include <iostream>
#include "library.hpp"
#include "utils.hpp"

using namespace std;

void testdrive();
int main(int argc, char **argv) {

	Library theLibrary("Exodus");
	


	theLibrary.launch();

	//testdrive();
	return 0;
}

void testdrive(){

	string theString{"abcd"}, prefix("ab");

	if (is_starts_with( theString, prefix) ){
		message("Matching prefix");
	}

	prefix ="xy";

	if (is_starts_with( theString, prefix) ){
		message("Matching prefix");
	}
	else {
		message("Not Matching prefix");
	}


}



