#ifndef ENROLLMENT_MANAGEMENT_H
#define ENROLLMENT_MANAGEMENT_H

#include <iostream>
#include <memory>
#include "Employee.h"
#include "Course.h"
#include "Enrollment.h"
#include "Logger.h" 

class EnrollmentManager {
private:
    map<int, vector<shared_ptr<Enrollment>>> enrollmentsMap;

public:
    // Function to add enrollments
    void addEnrollment(const shared_ptr<Employee>& employee, const shared_ptr<Course>& course) {
        try {
            // Log the start of the function
            Logger::log("Adding enrollment for Employee ID: " + to_string(employee->Employee_ID));

            enrollmentsMap[employee->Employee_ID].push_back(make_shared<Enrollment>(employee, course));

            // Log the end of the function
            Logger::log("Enrollment added successfully for Employee ID: " + to_string(employee->Employee_ID));
        }
        catch (const std::exception& e) {
            // Log error if an exception occurs during addEnrollment
            Logger::error("Exception occurred during adding enrollment: " + string(e.what()));
        }
    }

    // Function to display all enrollments for a specific employee
    void displayEnrollmentsForEmployee(int employeeID) {
        try {
            // Log the start of the function
            Logger::log("Displaying enrollments for Employee ID: " + to_string(employeeID));

            cout << "Enrollments for Employee ID: " << employeeID << endl;
            for (const auto& enrollment : enrollmentsMap[employeeID]) {
                cout << "Course: " << enrollment->course->Course_title << endl;
            }
            cout << endl;

            // Log the end of the function
            Logger::log("Enrollments for Employee ID: " + to_string(employeeID) + " displayed successfully.");
        }
        catch (const std::exception& e) {
            // Log error if an exception occurs during displayEnrollmentsForEmployee
            Logger::error("Exception occurred during displaying enrollments for Employee ID: " + to_string(employeeID) + " - " + string(e.what()));
        }
    }



void displayAllEnrollments() {
    try {
        // Log the start of the function
        Logger::log("Displaying all enrollments.");

        cout << "All Enrollments:\n";
        for (const auto& entry : enrollmentsMap) {
            int employeeID = entry.first;
            cout << "Employee ID: " << employeeID << endl;
            for (const auto& enrollment : entry.second) {
                cout << "Course: " << enrollment->course->Course_title << endl;
            }
            cout << endl;
        }

        // Log the end of the function
        Logger::log("All enrollments displayed successfully.");
    }
    catch (const std::exception& e) {
        // Log error if an exception occurs during displayAllEnrollments
        Logger::error("Exception occurred during displaying all enrollments: " + string(e.what()));
    }
}

// ...

};

#endif  //ENROLLMENT_MANAGEMENT_H
