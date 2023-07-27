#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include"Employee.h"
#include"Course.h"
#include"Enrollment.h"
#include"Enrollment_Management.h"
#include"Training_Manager.h"
#include"Proxy.h"

using namespace std;



int main() {

    Proxy p;

    cout << "=== Course Details ===" << endl;
    // Get courses from user input
    p.addCourse();

    cout << "\n=== Employee Details ===" << endl;
    // Get employees from user input
    p.addEmployee();

    cout << "\n=== Enrollment Details ===" << endl;
    // Get enrollments based on user input
    p.enrollEmployeeInCourse();

    p.generateReport();

    return 0;
}