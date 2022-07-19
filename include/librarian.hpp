
#ifndef INCLUDE_LIBRARIAN_HPP_
#define INCLUDE_LIBRARIAN_HPP_

#include <iostream>
#include <string>

#include "person.hpp"

using namespace std;

class Librarian : public Person {
    public:
        Librarian(string firstName, string lastName, string email, string address);


};

#endif 

