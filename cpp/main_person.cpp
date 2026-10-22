#include <iostream>
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>
#include "person/person.hpp"

int main() {
    std::ifstream file("person/data.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open person/data.json\n";
        return 1;
    }

    nlohmann::json data = nlohmann::json::parse(file);

    std::vector<Person> people;
    for (const auto& entry : data) {
        people.emplace_back(entry);
    }

    for (auto& p : people) {
        std::cout << "First:  " << p.getFirstName()    << "\n";
        std::cout << "Last:   " << p.getLastName()     << "\n";
        std::cout << "SSN:    " << p.getSSN()           << "\n";
        std::cout << "Mobile: " << p.getMobileNumber() << "\n\n";
    }

    return 0;
}
