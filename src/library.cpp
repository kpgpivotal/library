#include "library.hpp"
#include "utils.hpp"
#include "librarian.hpp"

Library::Library( string name) : mName {name} {

}

void Library::launch() {

	cout << "Starting the Library application..." << endl;
	mpLibrarian = new Librarian("Anthony", " Gates","librarian@library.com", "Villa 1, Posh Avenue, CA");
	message(mpLibrarian->getName());

	show_menu();
}




int Library::show_menu(){
	int choice{};

	cout << "Welcome to " << mName << " Library" << endl;
	
	while (true) {
		print_line();
		message("\t\tLibrary Menu :");
		message("1) Add book");
		message("2) Search Books by prefix");
		message("3) Print who borrowed book by name");
		message("4) Print library by id");
		message("5) Print library by name");
		message("6) Add user");
		message("7) Borrow book");
		message("8) Return book");
		message("9) Print users");
		message("10) Exit");
		print_line();

		choice = read_numeric_input("Invalid value. Please enter numeric value.");
		
		if ( EXIT_MENU_CHOICE == choice) {
			message("Thanks you. Looking forward to your next visit.\n");
			break;
		}

		process_user_choice(choice);
		
	}

	return 1;
}

int Library::process_user_choice( int choice) {

	switch ( choice ) {
		case 1 : {
			add_book();
			break;
		}

		default : {
			message("Invalid input. Please try again");
		}
	}
	return 1;
}

int Library::add_book(){
	message("Adding Book...");

	return 1;
}