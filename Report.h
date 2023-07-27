#include <iostream>
#include <vector>
#include "Employee.h"
#include "Course.h"
#include "Enrollment.h"
#include "Enrollment_Management.h"
#include "Logger.h"

enum class ReportType { GENERAL };

template <ReportType type>
class Report {
public:
    static void generateReport(const std::vector<std::shared_ptr<Course>>& courses,
                               const std::vector<std::shared_ptr<Employee>>& employees,
                                EnrollmentManager& enrollmentManager);
};

template <>
void Report<ReportType::GENERAL>::generateReport(const std::vector<std::shared_ptr<Course>>& courses,
                                                 const std::vector<std::shared_ptr<Employee>>& employees,
                                                  EnrollmentManager& enrollmentManager) {
    try {
        // Log the start of the function
        Logger::log("Generating report.");

        std::cout << "\n=== Generating Report ===" << std::endl << std::endl;

        std::cout << "\n=== Course Details ===" << std::endl;
        // Display Course details
        for (const auto& course : courses) {
            course->displayCourseDetails();
            std::cout << std::endl;
        }

        std::cout << "\n=== Employee Details ===" << std::endl;
        // Display Employee details
        for (const auto& employee : employees) {
            employee->displayEmployeeDetails();
            std::cout << std::endl;
        }

        std::cout << "\n=== Enrollment Details ===" << std::endl;
        // Display all enrollments for a specific employee (e.g., Employee ID 1)
        int employeeIDToDisplay = 1;
        enrollmentManager.displayEnrollmentsForEmployee(employeeIDToDisplay);

        // Display all enrollments
        enrollmentManager.displayAllEnrollments();

        // Log the end of the function
        Logger::log("Report generated successfully.");
    }
    catch (const std::exception& e) {
        // Log error if an exception occurs during generateReport
        Logger::error("Exception occurred during generating report: " + std::string(e.what()));
    }
}
