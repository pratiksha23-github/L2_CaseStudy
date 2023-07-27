#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include "Logger.h"
using namespace std;

class Course {
public:
    int Course_ID;
    string Course_title, Course_description, Course_instructor;

    // Constructor for course
    Course(int ID, string title, string description, string instructor) {
        try {
            if (ID > 0) {
                this->Course_ID = ID;
                this->Course_title = title;
                this->Course_description = description;
                this->Course_instructor = instructor;

                // Log course creation
                Logger::log("Course '" + Course_title + "' has been created.");
            } else {
                throw std::invalid_argument("Invalid Course ID");
            }
        } catch (const std::exception& e) {
            Logger::error("System has encountered an error at Course class. Error: " + string(e.what()));
        }
    }

    // void getCourse();
    void displayCourseDetails() {
        try {
            cout << "ID: " << Course_ID << endl;
            cout << "Title: " << Course_title << endl;
            cout << "Description: " << Course_description << endl;
            cout << "Instructor: " << Course_instructor << endl;
            Logger::log("Displaying Course details for course id: " + to_string(Course_ID));
        } catch (const std::exception& e) {
            Logger::error("System has encountered an error at Course class. Error: " + string(e.what()));
        }
    }

    // Destructor for course
    ~Course() {
        cout << "Course '" << Course_title << "' has been destroyed.\n";
        // Log course destruction
        Logger::log("Course '" + Course_title + "' has been destroyed.");

        // Log an error if the Course_ID is invalid
        if (Course_ID < 0) {
            Logger::error("Invalid Course ID encountered during destruction.");
        }
    }
};

#endif // COURSE_H
