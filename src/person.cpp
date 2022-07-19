#include "person.hpp"
#include "utils.hpp"

Person::Person(string firstName, string lastName, string email, string address)
    :  mEmail{email}  {

    mFirstName = capitalizeFirstLetter(firstName);
    mLastName = capitalizeFirstLetter(lastName);
    mAddress = capitalizeFirstLetter(address);

}

string Person::getName(){
    return mFirstName + " " + mLastName;
}

string Person::getEmail(){
    return mEmail;
}
    

