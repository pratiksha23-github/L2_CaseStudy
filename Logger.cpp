#include "Logger.h"

void Logger::log(const std::string& message) {
    std::ofstream logFile("log.txt", std::ios::app); // Open the log file in append mode
    if (logFile.is_open()) {
        logFile << "[LOG]: " << message << std::endl;
        logFile.close();
    }
}

void Logger::error(const std::string& message) {
    std::ofstream errorFile("error.log", std::ios::app); // Open the error log file in append mode
    if (errorFile.is_open()) {
        errorFile << "[ERROR]: " << message << std::endl;
        errorFile.close();
    }
}
