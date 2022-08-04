#include "member.hpp"




ostream& operator<< (ostream& os, const Member& rhs){
    os << rhs.getName() << "\t" <<rhs.getEmail() << endl;

    return os;
}

bool operator== (const Member& lhs, const Member& rhs){

    if ( lhs.getEmail().compare(rhs.getEmail()) == 0) {
        return true;
    }

    return false;
}

Member::Member():Person( "",  "",  "",  "") {}
Member::Member(string firstName, string lastName, string email, string address):
         Person( firstName,  lastName,  email,  address) {}

Member::Member(string firstName, string email):  Person( firstName,  email  ) {}


int  Member::borrow_book(long book_id){

    if (MAXIMUM_BOOKS_BORROW_LIMIT == m_borrowed_book_list.size()){
        message(MAX_BOOK_BORROW_LIMIT_MESSAGE);
        return 0;
    }

    m_borrowed_book_list.push_back(book_id);
    return 1;
}

long  Member::return_book(long book_id){
    long ret_book_id{0}; 

    auto itr  = find(m_borrowed_book_list.begin(), m_borrowed_book_list.end(), book_id);
	if ( itr != m_borrowed_book_list.end()) {
        ret_book_id =(*itr);
		m_borrowed_book_list.erase(itr);
        return ret_book_id;
    }

    message("This book is not borrowed by the member.");
    return 0;
}



