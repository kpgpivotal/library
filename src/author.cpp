#include "author.hpp"

Author::Author(string firstName, string lastName, string email, string address)
    :  Person( firstName,  lastName,  email,  address) {}


ostream& operator<< (ostream& os,  Author& rhs){
    os << rhs.getName();

    return os;
}