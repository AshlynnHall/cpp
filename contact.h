#pragma once
#include <string>
#include <memory>

class Contact {
public:
    std::string streetAddress;
    std::string city;
    std::string state;
    std::string zipCode;
    std::string phoneNumber;

    Contact();
    void inputContactInfo();
    void displayContactInfo() const;
};