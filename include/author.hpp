#ifndef INCLUDE_AUTHOR_HPP_
#define INCLUDE_AUTHOR_HPP_

#include <iostream>
#include <string>
#include "person.hpp"

using namespace std;

class Author : public Person {
    friend ostream& operator<< (ostream& os,  Author& rhs);
    public:
        Author(string mFirstName, string mLastName, string mEmail, string maddress);

};

#endif