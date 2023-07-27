#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include "Logger.h"
using namespace std;

class Employee {
public:
    int Employee_ID;
    string Employee_name, Employee_position, Employee_department;

    // Constructor for Employee
    Employee(int ID, string name, string position, string department) {
        try {
            if (ID > 0) {
                this->Employee_ID = ID;
                this->Employee_name = name;
                this->Employee_position = position;
                this->Employee_department = department;
            } else {
                throw std::invalid_argument("Invalid Employee ID");
            }
        }
        catch (const std::exception& e) {
            // Log error if an exception occurs during Employee construction
            Logger::error("Exception occurred during Employee construction: " + string(e.what()));
            throw; 
        }
    }

    void displayEmployeeDetails() {
        try {
            // Log the start of the function
            Logger::log("Displaying employee details for '" + Employee_name + "'.");

            cout << "ID: " << Employee_ID << endl;
            cout << "Name: " << Employee_name << endl;
            cout << "Position: " << Employee_position << endl;
            cout << "Department: " << Employee_department << endl;

            // Log the end of the function
            Logger::log("Employee details for '" + Employee_name + "' displayed successfully.");
        }
        catch (const std::exception& e) {
            // Log error if an exception occurs during displayEmployeeDetails
            Logger::error("Exception occurred during displaying employee details: " + string(e.what()));
        }
    }

    // Destructor for Employee
    ~Employee() {
        cout << "Employee '" << Employee_name << "' has been removed.\n";
    }
};

#endif // EMPLOYEE_H
