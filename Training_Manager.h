#ifndef TRAINING_MANAGER_H
#define TRAINING_MANAGER_H

#include <iostream>
#include <memory>
#include "Employee.h"
#include "Course.h"
#include "Enrollment.h"
#include "Enrollment_Management.h"
#include "Report.h"

using namespace std;

class Training_Manager
{
public:
    vector<shared_ptr<Course>> addCourses();
    vector<shared_ptr<Employee>> addEmployees();
    vector<shared_ptr<Enrollment>> addEnrollments(const vector<shared_ptr<Employee>> &Employee, const vector<shared_ptr<Course>> &Course);
    void generateReport(const vector<shared_ptr<Course>> &Course, const vector<shared_ptr<Employee>> &Employee, EnrollmentManager);
};
// Function to add courses based on user input
vector<shared_ptr<Course>> Training_Manager::addCourses()
{
    vector<shared_ptr<Course>> courses;
    char addAnother = 'y';
    try
    {
        // Log the start of the function
        Logger::log("Adding courses.");

        while (addAnother == 'y' || addAnother == 'Y')
        {
            int ID;
            string title, description, instructor;

            cout << "Enter Course ID: ";
            cin >> ID;
            cin.ignore(); // Ignore the newline character

            cout << "Enter Course Title: ";
            getline(cin, title);

            cout << "Enter Course Description: ";
            getline(cin, description);

            cout << "Enter Instructor Name: ";
            getline(cin, instructor);

            courses.push_back(make_shared<Course>(ID, title, description, instructor));

            cout << "Do you want to add another course? (y/n): ";
            cin >> addAnother;
            cout << endl;
            cin.ignore(); // Ignore the newline character
        }
        // Log the end of the function
        Logger::log("Courses added successfully.");
    }
    catch (const std::exception &e)
    {
        // Log error if an exception occurs during addCourses
        Logger::error("Exception occurred during adding courses: " + string(e.what()));
    }
    return courses;
}

// Function to add employees based on user input
vector<shared_ptr<Employee>> Training_Manager::addEmployees()
{
    vector<shared_ptr<Employee>> employees;
    char addAnother = 'y';
    try
    {
        // Log the start of the function
        Logger::log("Adding employees.");

        while (addAnother == 'y' || addAnother == 'Y')
        {
            int ID;
            string name, position, department;

            cout << "Enter Employee ID: ";
            cin >> ID;
            cin.ignore(); // Ignore the newline character

            cout << "Enter Employee Name: ";
            getline(cin, name);

            cout << "Enter Employee Position: ";
            getline(cin, position);

            cout << "Enter Employee Department: ";
            getline(cin, department);

            employees.push_back(make_shared<Employee>(ID, name, position, department));

            cout << "Do you want to add another employee? (y/n): ";
            cin >> addAnother;
            cout << endl;
            cin.ignore(); // Ignore the newline character
        }
        // Log the end of the function
        Logger::log("Employees added successfully.");
    }
    catch (const std::exception &e)
    {
        // Log error if an exception occurs during addEmployees
        Logger::error("Exception occurred during adding employees: " + string(e.what()));
    }
    return employees;
}

// Function to add enrollments based on user input
vector<shared_ptr<Enrollment>> Training_Manager::addEnrollments(const vector<shared_ptr<Employee>> &employees, const vector<shared_ptr<Course>> &courses)
{
    vector<shared_ptr<Enrollment>> enrollments;
    try
    {
        // Log the start of the function
        Logger::log("Enrolling employees in courses.");

        char addAnother = 'y';

        while (addAnother == 'y' || addAnother == 'Y')
        {
            int empID, courseID;

            cout << "Enter Employee ID for enrollment: ";
            cin >> empID;

            cout << "Enter Course ID for enrollment: ";
            cin >> courseID;

            // Find corresponding employee and course using empID and courseID
            shared_ptr<Employee> employee = nullptr;
            shared_ptr<Course> course = nullptr;

            for (const auto &emp : employees)
            {
                if (emp->Employee_ID == empID)
                {
                    employee = emp;
                    break;
                }
            }

            for (const auto &crs : courses)
            {
                if (crs->Course_ID == courseID)
                {
                    course = crs;
                    break;
                }
            }

            if (employee && course)
            {
                enrollments.push_back(make_shared<Enrollment>(employee, course));
            }
            else
            {
                cout << "Employee or Course not found. Please try again.\n";
            }

            cout << "Do you want to add another enrollment? (y/n): ";
            cin >> addAnother;
            cout << endl;
        }

        // Log the end of the function
        Logger::log("Employees enrolled in courses successfully.");
    }
    catch (const std::exception &e)
    {
        // Log error if an exception occurs during addEnrollments
        Logger::error("Exception occurred during enrolling employees in courses: " + string(e.what()));
    }

    return enrollments;
}

void Training_Manager ::generateReport(const vector<shared_ptr<Course>> &courses, const vector<shared_ptr<Employee>> &employees, EnrollmentManager enrollmentManager)
{
     Report<ReportType::GENERAL>::generateReport(courses, employees, enrollmentManager);
}

#endif // TRAINING_MANAGER_H