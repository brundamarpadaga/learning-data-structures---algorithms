#pragma once
#include <string>
#include <nlohmann/json.hpp>

class Person {
public:
    Person(const nlohmann::json& data);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getSSN() const;          // returns "N/A" if missing
    std::string getMobileNumber() const; // returns "N/A" if no mobile contact

private:
    nlohmann::json _person;
};
