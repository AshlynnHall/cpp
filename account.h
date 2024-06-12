#pragma once
#define account_h
#include <string>
#include <list>
#include "contact.h"
#include <memory>

class Account
{
private:
    static int nextAccountId;
public:
    int accountId;
    std::string accountName;
    float accountBalance;
    std::shared_ptr<Contact> contactInfo;

    Account();
    Account(std::string name, float balance);

    void inputAccountInfo();
    void displayAccountInfo() const;
    void deposit(float amount);
    void withdraw(float amount);
    float get_balance() const;
    void apply_dividend(float percentage);
    void addContactInfo();
};
