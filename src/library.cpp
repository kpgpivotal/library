#include "library.hpp"
#include "utils.hpp"
//#include "librarian.hpp"
#include "author.hpp"
#include "book.hpp"
#include "member.hpp"

Library::Library(string name ) :mName{name}{ }

void Library::launch() {

	cout << "Starting the Library application..." << endl;
	//mpLibrarian = new Librarian("Anthony", " Gates","librarian@library.com", "Villa 1, Posh Avenue, CA");
	//message(mpLibrarian->getName());

	show_menu();
}




int Library::show_menu(){
	int choice{};
	string input{};

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
		message("\nPlease enter your choice as numeric value :");
		

		//message("Invalid value. Please enter numeric value.");
		std::getline(std::cin, input);
		
		print_line();
		try{
			choice = stoi(input);
			cout << choice << " ";
		}
		catch(...){

		}
		
		
		
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

		case 2 : {
			search_books_prefix();
			break;
		}

		case 4 : {
			print_library_by_id();
			break;
		}

		case 5 : {
			print_library_by_bookname();
			break;
		}

		case 6 : {
			add_user();
			break;
		}

		case 7 : {
			borrow_book();
			break;
		}

		case 8 : {
			return_book();
			break;
		}

		case 9 : {
			print_members();
			break;
		}

		default : {
			message("Invalid input. Please try again");
		}
	}
	return 1;
}

int Library::return_book(){
	string email{};
	long book_id{};
	Member *borrower_ptr = nullptr;

	email = get_input_email(EMAIL_INPUT_PROMPT);
	borrower_ptr = get_member_by_email( email);
	if ( nullptr == borrower_ptr ){

		return 0;
	}

	book_id = get_input_long(BOOK_ID_INPUT_PROMPT);

	book_id = borrower_ptr->return_book(book_id);
	if (0 == book_id) {
		return 0;
	}

	// return 
	Book *theBookPtr = get_book_by_id( book_id);
	if (nullptr == theBookPtr) {
		message("No book is borrowed by " + borrower_ptr->getName() + ".");
		return 0;
	}

	Book *updated_book_ptr = theBookPtr->return_book(*borrower_ptr);
	if (nullptr == updated_book_ptr){
		message("Unable to return the book  borrowed by " + borrower_ptr->getName() + ".");
		return 0;
	}

	
	// update list 
	std::replace(mBookList.begin(), mBookList.end(), *theBookPtr, *updated_book_ptr);
	
	return 1;
}

int Library::borrow_book(){
	string email{};
	long book_id{};
	Member *borrower_ptr = nullptr;
	int borrow_check{};

	email = get_input_email(EMAIL_INPUT_PROMPT);
	borrower_ptr = get_member_by_email( email);
	if ( nullptr == borrower_ptr ){

		return 0;
	}

	//get the book
	book_id = get_input_long(BOOK_ID_INPUT_PROMPT);
	Book *theBookPtr = get_book_by_id(book_id);
	message("Selected book is : " + theBookPtr->getName()  );
	if (false == theBookPtr->isAvailable()){
		message("Sorry this book in not avaialbel now. Try later.");
		return 0;
	}
	char confirm_book = getCharValidInput("Do you want to proceed with borrowing? (Y/N)", 'Y', 'N');
	if ( 'N' == confirm_book) {
		return 0;
	}
	//check the maximum limit
	if ( 0 == borrower_ptr->borrow_book(book_id)) {
		return 0;
	}


	// borrow
	borrow_check = theBookPtr->borrow_book(*borrower_ptr);
	if (borrow_check == 0 ){
		return 0;
	}

	
	// update list 
	std::replace(mBookList.begin(), mBookList.end(), *theBookPtr, *theBookPtr);
	
	return 1;
}

Book* Library::get_book_by_id(long id){
	if (mBookList.size() == 0 ) {
		message(BOOK_LIST_EMPTY_MESSAGE);
		return nullptr;
	}

	for (auto itr = mBookList.begin(); itr != mBookList.end(); ++itr) {
		Book the_book = *itr;
		if ( the_book.getId() == id){
			return &(*itr);
		}
	}

	message("Unable to find the Book with given id.");
	return nullptr;
}

Member* Library::get_member_by_email(string email){
	if (mMemberList.size() == 0 ) {
		message(EMPTY_MEMBER_LIST_MESSAGE);
		return nullptr;
	}

	for (auto itr = mMemberList.begin(); itr != mMemberList.end(); ++itr) {
		Member the_member = *itr;
		if (the_member.getEmail().compare(email) ==0 ) {
			return &(*itr);
		}

	}

	message(MEMBER_NOT_FOUND_WITH_GIVEN_EMAIL);
		return nullptr;
}

int Library::print_members(){
	cout << "Name            \tEmail" << endl ;
	for (const Member theMember : mMemberList) {
        cout << theMember;
    }

	cout << endl;
	return 1;
}

int Library::add_user(){
	string name{}, email{};

	//name = get_input_string("Please enter user name ");
	//email = get_input_string("Please enter email ");
	name = "Anil";
	email = "anil@email.com";
	Member new_member{name,email};
	add_user_to_list(new_member);

	name = "Binil";
	email = "binil@email.com";
	Member new_member2{name,email};
	add_user_to_list(new_member2);

	
	return 1;
}

int Library::add_user_to_list(Member new_member){
	if (mMemberList.size() == 0 ) {
		mMemberList.push_back(new_member);
		message("New member " + new_member.getName() + " added.");
		return 1;
	}

	auto itr  = find(mMemberList.begin(), mMemberList.end(), new_member);
	if ( itr != mMemberList.end()) {
		message(new_member.getName() + " is alreday a memeber.");
	}
	else {
		mMemberList.push_back(new_member);
		message("New member " + new_member.getName() + " added.");
	}

	return 1;
}

int Library::add_book(){
	message("Adding Book...");
	Author author{"Charles", "Petzold", "charles@microsoft.com", "#1, Royal street, New York"};
	Book book1{"Windows Programming", author, 10};
	check_add_new_book(book1);
	

	Author author2{"Brian", "Kernighan", "brian@att.com", "#2, ATT street, CA"};
	Author author3{"Dennis", "Ritchie", "dennis@bdu.com", "#1, Royal street, CA"};
	Author author4{"King", "George", "king@bdu.com", "#1, Royal street, CA"};

	Book book2{"The C Programming Language", author2, author3, 10};
	Book book3{"The Titanic", author4,  15};
	Book book4{"Ant story", author4,  5};
	check_add_new_book(book2);
	check_add_new_book(book3);
	check_add_new_book(book3);
	check_add_new_book(book4);

	return 1;
}


int Library::check_add_new_book(Book& theBbook){

	if (mBookList.size() == 0 ) {
		mBookList.push_back(theBbook);
		message(theBbook.getName() + " added.");
		return 1;
	}

	auto itr  = find(mBookList.begin(), mBookList.end(), theBbook);
	if ( itr != mBookList.end()) {
		int index = itr - mBookList.begin();

		Book new_book = *itr;
		cout << "new_book " << new_book.getName();
		new_book += theBbook;
		mBookList[index] = new_book;
		std::replace(mBookList.begin(), mBookList.end(), theBbook, new_book);
		//mBookList.erase(*itr);
		//mBookList.push_back(new_book);
		message("Book was alredy there in the libaray and its quantity id updated.");
	}
	else {
		mBookList.push_back(theBbook);	
	}

	return 1;
}


int Library::print_library_by_bookname(){

	sort(mBookList.begin(), mBookList.end());

	cout << "Name            \tAuthor(s)      \'Total quantity\'  \'Borrowed quantity\'" << endl ;
	for (const Book theBook : mBookList) {
        cout << theBook;
    }

	cout << endl;
	return 1;
}

bool compare_by_id(Book& b1, Book& b2)
{
    return (b1.getId() < b2.getId());
}

int Library::print_library_by_id(){
	// sort by id
	sort(mBookList.begin(), mBookList.end(),compare_by_id);
	cout << "Name            \tAuthor(s)      \'Total quantity\'  \'Borrowed quantity\'" << endl ;
	for (const Book theBook : mBookList) {
        cout << theBook;
    }

	cout << endl;
	return 1;
}

int Library::search_books_prefix(){
	string prefix{};
	string book_name;
	int i{0};

	prefix = get_input_string(SEARCH_BOOKS_BY_PREFIX_PROMPT);

	message("\nBooks with matching prefix:");
	for (const Book theBook : mBookList) {
		book_name = theBook.getName();
		//cout << theBook;
		
		if (is_starts_with(book_name, prefix)) {
			cout << ++i << "\t" << theBook.getName() << endl ;
		}
        
    }

	return 1;
}