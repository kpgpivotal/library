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

int main(int argc, char **argv) {

	Library theLibrary("Exodus");
	
	log_info("Testdrive boost looger");
	theLibrary.launch();

	return 0;
}



