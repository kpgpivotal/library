#include "library.hpp"
#include "utils.hpp"
#include "librarian.hpp"
#include "author.hpp"
#include "book.hpp"

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

		case 4 : {
			print_library_by_bookname();
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
	Author author{"Charles", "Petzold", "charles@microsoft.com", "#1, Royal street, New York"};
	Book book1{"Windows Programming", author, 10};
	mBookList.push_back(book1);

	Author author2{"Brian", "Kernighan", "brian@att.com", "#2, ATT street, CA"};
	Author author3{"Dennis", "Ritchie", "dennis@bdu.com", "#1, Royal street, CA"};
	Book book2{"The C Programming Language", author2, author3, 10};
	mBookList.push_back(book2);


	return 1;
}


int Library::print_library_by_bookname(){
	cout << "Name              \t\tAuthor(s)      \'Total quantity\'  \'Borrowed quantity\'" << endl ;
	for (const Book theBook : mBookList) {
        cout << theBook;
    }

	return 1;
}