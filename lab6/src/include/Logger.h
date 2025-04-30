#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Logger {
public:
    virtual void notify(const std::string& event) = 0;
    virtual ~Logger() = default;
};

class ConsoleLogger : public Logger {
public:
    void notify(const std::string& event) override {
        std::cout << "Event: " << event << std::endl;
    }
};

class FileLogger : public Logger {
    std::string filename;

public:
    explicit FileLogger(const std::string& filename) : filename(filename) {}

    void notify(const std::string& event) override {
        std::ofstream logFile(filename, std::ios::app);
        if (!logFile) throw std::runtime_error("Failed to open log file.");
        logFile << "Event: " << event << std::endl;
    }
};