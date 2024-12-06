#pragma once
#include <string>

class Doctor {

public:
    Doctor(const std::string& name, const std::string& specialty, const std::string& schedule);

    std::string getName() const;

    std::string getSpecialty() const;

    std::string getSchedule() const;

    void printInfo() const;

private:
    std::string name;
    std::string specialty;
    std::string schedule;
};