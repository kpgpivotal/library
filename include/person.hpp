#ifndef INCLUDE_PERSON_HPP_
#define INCLUDE_PERSON_HPP_

#include <iostream>
#include <string>
#include "utils.hpp"

using namespace std;

class Person {
    public:
        Person(string mFirstName, string mLastName, string mEmail, string maddress);
        Person(string firstName, string email);
        virtual  string getName() const;
        virtual string getEmail() const;

    private:
        string mFirstName;
        string mLastName;
        string mEmail;
        string mAddress;


};


#endif /* INCLUDE_PERSON_HPP_ */