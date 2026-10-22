#include "person.hpp"

Person::Person(const nlohmann::json& data) : _person(data) {}

std::string Person::getFirstName() const {
    return _person["name"]["first"];
}

std::string Person::getLastName() const {
    return _person["name"]["last"];
}

std::string Person::getSSN() const {
    if (!_person.contains("identity")) {
        return "N/A";
    }
    if (!_person["identity"].contains("ssn")) {
        return "N/A";
    }
    return _person["identity"]["ssn"];
}

std::string Person::getMobileNumber() const {
    if (!_person.contains("contacts")) {
        return "N/A";
    }
    for (const auto& contact : _person["contacts"]) {
        if (contact["type"] == "mobile") {
            return contact["number"];
        }
    }
    return "N/A";
}
