#include "person.hpp"
#include "utils.hpp"

Person::Person() : mFirstName{""},mLastName{""},mAddress{""} , mEmail{""} {}
Person::Person(string firstName, string lastName, string email, string address)
    :  mEmail{email}  {

    mFirstName = capitalizeFirstLetter(firstName);
    mLastName = capitalizeFirstLetter(lastName);
    mAddress = capitalizeFirstLetter(address);

}

Person::Person(string firstName, string email) : mEmail{email} {
    mFirstName = capitalizeFirstLetter(firstName);
}

string  Person::getName() const{
    return mFirstName + " " + mLastName;
}

string Person::getEmail() const{
    return mEmail;
}
    

