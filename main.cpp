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
	
	//init_logging();
	log_info("Testdrive boost logger11");
	log_debug("Testdrive boost debug logger22");

	theLibrary.launch();

	return 0;
}



