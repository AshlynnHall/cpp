#include "Account.h"
#include "Contact.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>
#include <memory>
#include <string>

void display_accounts(const std::list<Account>& accountList) {
    std::for_each(accountList.begin(), accountList.end(), [](const Account& account) {
        account.displayAccountInfo();
    });
    /*/for (const auto& account : accountList) {
        account.displayAccountInfo();
    } /*/
}

std::list<Account>::iterator find_account_by_id(std::list<Account>& accountList, int id) {
    for (auto it = accountList.begin(); it != accountList.end(); ++it) {
        if (it->accountId == id) {
            return it;
        }
    }
    return accountList.end();
}

int main() {
    std::list<Account> accounts;
    int choice;
    float depositAmount;
    float withdrawAmount;
    int accountIdToFind;


    do {
        std::cout << "" << std::endl;
        std::cout << "Menu:" << std::endl;
        std::cout << "0. Quit" << std::endl;
        std::cout << "1. Display Account Information" << std::endl;
        std::cout << "2. Add Deposit" << std::endl;
        std::cout << "3. Withdrawal" << std::endl;
        std::cout << "4. Add new account" << std::endl;
        std::cout << "5. Find account by ID" << std::endl;
        std::cout << "6. Remove account by ID" << std::endl;
        std::cout << "7. Show total balance for all accounts" << std::endl;
        std::cout << "8. Add a dividend to all accounts" << std::endl;
        std::cout << "9. Add contact information to an account" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> choice;
        std::cin.get();

        switch (choice) {
        case 0:
            break;
        case 1:
            display_accounts(accounts);
            break;
        case 2:
            std::cout << "Enter your deposit amount: ";
            std::cin >> depositAmount;
            std::cout << "Enter the account ID to deposit to: ";
            int depositAccountId;
            std::cin >> depositAccountId;
            for (auto& account : accounts) {
                if (account.accountId == depositAccountId) {
                    account.deposit(depositAmount);
                    break;
                }
            }
            break;
        case 3:
            std::cout << "Enter your withdrawal amount: ";
            std::cin >> withdrawAmount;
            std::cout << "Enter the account ID to withdraw from: ";
            int withdrawAccountId;
            std::cin >> withdrawAccountId;
            for (auto& account : accounts) {
                if (account.accountId == withdrawAccountId) {
                    account.withdraw(withdrawAmount);
                    break;
                }
            }
            break;
        case 4:
            {
                Account newAccount;
                newAccount.inputAccountInfo();
                accounts.push_back(newAccount);
            }
            break;
        case 5:
            std::cout << "Enter the ID of the account to find: ";
            std::cin >> accountIdToFind;
            {
                auto it = find_account_by_id(accounts, accountIdToFind);
                if (it != accounts.end()) {
                    std::cout << "Found account: ";
                    it->displayAccountInfo();
                }
                else {
                    std::cout << "Account not found." << std::endl;
                }
            }
            break;
        case 6: 
        {
            std::cout << "Enter the ID of the account to remove: ";
            int removeAccountId;
            std::cin >> removeAccountId;
            accounts.erase(std::remove_if(accounts.begin(), accounts.end(), [removeAccountId](const Account& account) {
                return account.accountId == removeAccountId;
                }), accounts.end());
            std::cout << "Account removed." << std::endl;
        }
        break;
        case 7:
        {
            float totalDeposits = std::accumulate(accounts.begin(), accounts.end(), 0.0f, [](float sum, const Account& account) {
                return sum + account.get_balance();
            });
            std::cout << "Total in all accounts: $" << totalDeposits << std::endl;
        }
        break;
        case 8:
        {
            std::cout << "Enter the dividend as a percentage: ";
            float dividendPercentage;
            std::cin >> dividendPercentage;
            std::transform(accounts.begin(), accounts.end(), accounts.begin(), [dividendPercentage](Account& account) {
                account.apply_dividend(dividendPercentage);
                return account;
                });
        }
        break;
        case 9:
        {
            std::cout << "Enter the ID of the account to add contact information to: ";
            int contactAccountId;
            std::cin >> contactAccountId;
            std::cin.ignore();
            for (auto& account : accounts) {
                if (account.accountId == contactAccountId) {
                    account.addContactInfo();
                    break;
                }
            }
        }
        break;
        default:
            std::cout << "Invalid choice. Please enter 0 or 1." << std::endl;
        }
    } while (choice != 0);

    return 0;
}