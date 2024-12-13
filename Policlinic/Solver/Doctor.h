#pragma once
#include <string>
#include <memory>
#include "Schedule.h"

class Doctor final : public std::enable_shared_from_this<Doctor> {
public:

    std::string getName() const;

    std::string getSpecialty() const;

    void printInfo() const;

private:
    Doctor(const std::string& name, const std::string& specialty);
    std::string name;
    std::string specialty;
    std::shared_ptr<Schedule> schedule;
};