#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream> // For file I/O
#include <string>

class Logger {
public:
    // Function to log a message to the log file
    static void log(const std::string& message);

    // Function to log an error to the error log file
    static void error(const std::string& message);
};

#endif // LOGGER_H
