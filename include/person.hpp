#ifndef INCLUDE_PERSON_HPP_
#define INCLUDE_PERSON_HPP_

#include <iostream>
#include <string>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <fmt/format.h>
#include <fstream>
#include <vector>

#include "utils.hpp"

using namespace std;

class Person {
     // declare serialize as a friend for direct access to private data
   template<typename Archive>
   friend void serialize(Archive& archive, Person& record);

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

// function template serialize is responsible for serializing and 
// deserializing Record objects to/from the specified Archive
template <typename Archive>
void serialize(Archive& archive, Person& record) {
   archive(cereal::make_nvp("mFirstName", record.mFirstName),
      cereal::make_nvp("mLastName", record.mLastName),
      cereal::make_nvp("mEmail", record.mEmail),
      cereal::make_nvp("mAddress", record.mAddress));
}

#endif /* INCLUDE_PERSON_HPP_ */