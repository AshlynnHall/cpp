#include "manager.h"
#include <iostream>

void Manager::addProject(const Project& project) {
    projects.push_back(project);
}

void Manager::updateProjectDetails(int index, const std::string& newName, const std::string& newClient, const std::string& newDeadline) {
    if (index >= 0 && index < projects.size()) {
        projects[index].updateDetails(newName, newClient, newDeadline);
    } else {
        std::cerr << "Invalid project index!" << std::endl;
    }
}

void Manager::displayAllProjects() const {
    for (const auto& project : projects) {
        project.displayInfo();
        std::cout << "-----------------" << std::endl;
    }
}