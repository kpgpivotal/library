#ifndef INCLUDE_PERSON_HPP_
#define INCLUDE_PERSON_HPP_

#include <iostream>
#include <string>

using namespace std;

class Person {
    public:
        Person(string mFirstName, string mLastName, string mEmail, string maddress);
        string getName();
        string getEmail();

    private:
        string mFirstName;
        string mLastName;
        string mEmail;
        string mAddress;


};


#endif /* INCLUDE_PERSON_HPP_ */