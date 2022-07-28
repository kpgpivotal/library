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


Member::Member(string firstName, string lastName, string email, string address):
         Person( firstName,  lastName,  email,  address) {}

Member::Member(string firstName, string email):  Person( firstName,  email  ) {}