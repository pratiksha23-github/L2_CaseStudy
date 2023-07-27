#ifndef PROXY_H
#define PROXY_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include "Employee.h"
#include "Course.h"
#include "Enrollment.h"
#include "Enrollment_Management.h"
#include "Training_Manager.h"
#include "Logger.h" 

class Proxy {
public:
    Proxy() : trainingManager(std::make_unique<Training_Manager>()) {}
    vector<shared_ptr<Course>> courses;
    vector<shared_ptr<Employee>> employees;
    vector<shared_ptr<Enrollment>> enrollments;
    EnrollmentManager enrollmentManager;

    void addCourse() {
        try {
            // Log the start of the function
            Logger::log("Adding courses.");

            courses = trainingManager->addCourses();

            // Log the end of the function
            Logger::log("Courses added successfully.");
        }
        catch (const std::exception& e) {
            // Log error if an exception occurs during addCourse
            Logger::error("Exception occurred during adding courses: " + string(e.what()));
        }
    }

    void addEmployee() {
        try {
            // Log the start of the function
            Logger::log("Adding employees.");

            employees = trainingManager->addEmployees();

            // Log the end of the function
            Logger::log("Employees added successfully.");
        }
        catch (const std::exception& e) {
            // Log error if an exception occurs during addEmployee
            Logger::error("Exception occurred during adding employees: " + string(e.what()));
        }
    }

    void enrollEmployeeInCourse() {
        try {
            // Log the start of the function
            Logger::log("Enrolling employees in courses.");

            enrollments = trainingManager->addEnrollments(employees, courses);

            // Add enrollments to the manager
            for (const auto& enrollment : enrollments) {
                enrollmentManager.addEnrollment(enrollment->employee, enrollment->course);
            }

            // Log the end of the function
            Logger::log("Employees enrolled in courses successfully.");
        }
        catch (const std::exception& e) {
            // Log error if an exception occurs during enrollEmployeeInCourse
            Logger::error("Exception occurred during enrolling employees in courses: " + string(e.what()));
        }
    }

    void generateReport() {
        try {
            // Log the start of the function
            Logger::log("Generating report.");

            trainingManager->generateReport(courses, employees, enrollmentManager);

            // Log the end of the function
            Logger::log("Report generated successfully.");
        }
        catch (const std::exception& e) {
            // Log error if an exception occurs during generateReport
            Logger::error("Exception occurred during generating report: " + string(e.what()));
        }
    }

private:
    std::unique_ptr<Training_Manager> trainingManager;
};

#endif //PROXY_H
