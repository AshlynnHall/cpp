#pragma once
#include "project.h"
#include <vector>

class Manager {
    public:
        void addProject(const Project& project);
        void updateProjectDetails(int index, const std::string& newName, const std::string& newClient, const std::string& newDeadline);
        void displayAllProjects() const;

    private:
        std::vector<Project> projects;
};