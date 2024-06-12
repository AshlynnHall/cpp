#include "Contact.h"
#include <iostream>
#include <memory>

Contact::Contact()
    : streetAddress(""), city(""), state(""), zipCode(""), phoneNumber("") {}

void Contact::inputContactInfo() {
    std::cout << "Enter street address: ";
    std::getline(std::cin, streetAddress);
    std::cout << "Enter city: ";
    std::getline(std::cin, city);
    std::cout << "Enter state: ";
    std::getline(std::cin, state);
    std::cout << "Enter zip code: ";
    std::getline(std::cin, zipCode);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);
}

void Contact::displayContactInfo() const {
    std::cout << "Street Address: " << streetAddress << std::endl;
    std::cout << "City: " << city << std::endl;
    std::cout << "State: " << state << std::endl;
    std::cout << "Zip Code: " << zipCode << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
}