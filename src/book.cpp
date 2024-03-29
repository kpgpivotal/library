#include "book.hpp"

Book::Book(): mId{0}, mName{""}, mAuthorName{""}, mTotalQuantity{0}, mBorrowedQuantity{0} {}
Book::Book( string name,  Author author, int quantity) : mName{name} ,
        mTotalQuantity{quantity}
{
    mId = ++BOOK_ID;
    mAuthorList.push_back(author);
    mAuthorName = author.getName();
    mBorrowedQuantity = 0;
}

Book::Book( string name,  Author author, Author author2,int quantity): mName{name} ,
        mTotalQuantity{quantity} 
{
    mId = ++BOOK_ID;
    mAuthorList.push_back(author);
    mAuthorName = author.getName();
    mAuthorList.push_back(author2);
    mAuthorName.append(" , ");
    mAuthorName.append(author2.getName());
    mBorrowedQuantity = 0;
}


string Book::get_borrowers_names() const{
    string borrowers_names{};
    bool is_first{true};
    
    for (const Member the_member : mBorrowedMemberList) {
        if (is_first){
            is_first = false;
            borrowers_names.append(the_member.getName());
        }
        else {
            borrowers_names.append(", ");
            borrowers_names.append(the_member.getName() );
        }
        
    }

    return borrowers_names;
}




ostream& operator<< (ostream& os, const Book& rhs){
    os << endl << rhs.mId << " " << rhs.mName << " " << rhs.mAuthorName << "\t" << rhs.mTotalQuantity << "\t" << rhs.mBorrowedQuantity;
    return os;
}

string Book::getAuthors(){
    string author_names{};
    bool is_first{true};

    for ( Author theauthor : mAuthorList) {
        if ( true == is_first) {
            is_first = false;
        }
        else {
            author_names.append(", ");      
        }

        author_names.append(theauthor.getName());
    }

    return author_names;
}

vector<Author> Book::getAuthorsList(){
    return mAuthorList;

}

bool Book::isAvailable(){
    if ( mBorrowedQuantity < mTotalQuantity ) {
        return true;
    }

    return false;
}

string Book::getName() const {
    return mName;
}

bool Book::operator< (const Book& rhs){
    if  ( mName < (rhs.mName) ){
        return true;
    }

    return false;
}

bool Book::operator== (const Book& rhs){
    return ( mName.compare(rhs.mName) == 0);
}

Book& Book::operator+= (const Book& rhs){
    mTotalQuantity += rhs.mTotalQuantity;
    mBorrowedQuantity += rhs.mBorrowedQuantity;
    return *this;
}

        
long Book::getId() const {
    return mId;
}     

int Book::borrow_book(Member member){
    // check if the book is already borrowed by same member.
    if ( true == is_already_borrowed_by_member( member)){
         message("Book " + mName + " is already borrowed by the member. ");
    return 0;
    } 

    if (isAvailable()) {
        ++mBorrowedQuantity;
        mBorrowedMemberList.push_back(member);
        message("Book " + mName + " is issued to " + member.getName() + ".");
        return 1;
    }

    message("Book " + mName + " is not avialble for borrowing. ");
    return 0;
}

Book* Book::return_book(Member member){
    --mBorrowedQuantity;

    auto itr  = find(mBorrowedMemberList.begin(), mBorrowedMemberList.end(), member);
	if ( itr != mBorrowedMemberList.end()) {
        mBorrowedMemberList.erase(itr);
        message("Book " + mName + " is returned by " + member.getName() + ".");
        return this;
    }

    message("Book " + mName + " is not borrowed by " + member.getName() + ".");
    return nullptr;

}

bool Book::is_already_borrowed_by_member(Member member){
    auto itr  = find(mBorrowedMemberList.begin(), mBorrowedMemberList.end(), member);
	if ( itr != mBorrowedMemberList.end()) {
        return true;
    }

    return false;
}