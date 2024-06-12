#include "account.h"
#include <string>
#include <iostream>
#include <list>
#include <memory>

int Account::nextAccountId = 0;

Account::Account() : accountName(""), accountBalance(0.0f), accountId(nextAccountId++), contactInfo(nullptr)
{
}

Account::Account(std::string name, float balance) :
    accountName(name), accountBalance(balance), accountId(nextAccountId++), contactInfo(nullptr)
{
}

void Account::inputAccountInfo() {
    std::cout << "Enter the name: ";
    std::getline(std::cin, accountName);
    std::cout << "Enter your initial balance: ";
    std::cin >> accountBalance;
    std::cin.ignore();
}


void Account::displayAccountInfo() const{
    std::cout << "Account ID: " << accountId << "  Name: " << accountName << "  Balance: $" << accountBalance << std::endl;
    if (contactInfo) {
        contactInfo->displayContactInfo();
    }
    else {
        std::cout << "No contact information available." << std::endl;
    }
}


void Account::deposit(float amount) {
    accountBalance += amount;
}

void Account::withdraw(float amount) {
    accountBalance -= amount;
}

float Account::get_balance() const {
    return accountBalance;
}

void Account::apply_dividend(float percentage) {
    accountBalance += accountBalance * (percentage / 100);
}


void Account::addContactInfo() {
    if (!contactInfo) {
        contactInfo = std::make_shared<Contact>();
    }
    contactInfo->inputContactInfo();
}