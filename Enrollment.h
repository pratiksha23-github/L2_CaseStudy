#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#include <iostream>
#include <memory>
#include "Employee.h"
#include "Course.h"
#include "Logger.h" 

using namespace std;

class Enrollment {
public:
    shared_ptr<Employee> employee;
    shared_ptr<Course> course;

    // Constructor for Enrollment
    Enrollment(shared_ptr<Employee> emp, shared_ptr<Course> crs)
        : employee(emp), course(crs) {
        try {
            // Log enrollment creation
            Logger::log("Enrollment for Employee '" + employee->Employee_name + "' in Course '" + course->Course_title + "' has been created.");
        }
        catch (const std::exception& e) {
            // Log error if an exception occurs during Enrollment construction
            Logger::error("Exception occurred during Enrollment construction: " + string(e.what()));
            throw; // Re-throw the exception to maintain the original behavior
        }
    }

    // Destructor for Enrollment
    ~Enrollment() {
        try {
            cout << "Enrollment for Employee '" << employee->Employee_name << "' in Course '" << course->Course_title << "' has been removed.\n";
            // Log enrollment destruction
            Logger::log("Enrollment for Employee '" + employee->Employee_name + "' in Course '" + course->Course_title + "' has been removed.");
        }
        catch (const std::exception& e) {
            // Log error if an exception occurs during Enrollment destruction
            Logger::error("Exception occurred during Enrollment destruction: " + string(e.what()));
        }
    }
};

#endif // ENROLLMENT_H
