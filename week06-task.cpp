#include <iostream>
#include "manager.h"
#include <limits>


void displayMenu() {
    std::cout << "" << std::endl;
    std::cout << "Web Project Manager Menu:" << std::endl;
    std::cout << "1. Add a new project" << std::endl;
    std::cout << "2. Update project details" << std::endl;
    std::cout << "3. Display all projects" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Choose an option: ";
}
int main()
{
    Manager manager;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            std::string name, client, deadline;
            std::cout << "Enter project name: ";
            std::getline(std::cin, name);
            std::cout << "Enter client name: ";
            std::getline(std::cin, client);
            std::cout << "Enter deadline (YYYY-MM-DD): ";
            std::getline(std::cin, deadline);

            Project newProject(name, client, deadline);
            manager.addProject(newProject);
            break;
        }
        case 2: {
            int index;
            std::string newName, newClient, newDeadline;
            std::cout << "Enter project index to update: ";
            std::cin >> index;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


            std::cout << "Enter new project name: ";
            std::getline(std::cin, newName);
            std::cout << "Enter client name: ";
            std::getline(std::cin, newClient);
            std::cout << "Enter new deadline (YYYY-MM-DD): ";
            std::getline(std::cin, newDeadline);

            manager.updateProjectDetails(index, newName, newClient, newDeadline);
            break;
        }
        case 3: {
            manager.displayAllProjects();
            break;
        }
        case 4: {
            std::cout << "Exiting..." << std::endl;
            break;
        }
        default: {
            std::cout << "Invalid option. Please try again." << std::endl;
            break;
        }
        }
    } while (choice != 4);

    return 0;
}
