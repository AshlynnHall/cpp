#include "project.h"
#include <iostream>

Project::Project(const std::string& name, const std::string& client, const std::string& deadline)
    : projectName(name), clientName(client), deadline(deadline) {}

void Project::updateDetails(const std::string& newName, const std::string& newClient, const std::string& newDeadline) {
    projectName = newName;
    clientName = newClient;
    deadline = newDeadline;
}

void Project::displayInfo() const {
    std::cout << "Project Name: " << projectName << std::endl;
    std::cout << "Client Name: " << clientName << std::endl;
    std::cout << "Deadline: " << deadline << std::endl;
}