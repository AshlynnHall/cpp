#pragma once
#include <string>

class Project {
    public:
        Project(const std::string& name, const std::string& client, const std::string& deadline);

        void updateDetails(const std::string& newName, const std::string& newClient, const std::string& newDeadline);
        void displayInfo() const;

    private:
        std::string projectName;
        std::string clientName;
        std::string deadline;
};