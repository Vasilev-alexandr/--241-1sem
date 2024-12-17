#pragma once
#include <string>
#include <memory>


class Schedule;

class Doctor final : public std::enable_shared_from_this<Doctor> {
public:

    static std::shared_ptr<Doctor> CreateDoctor(const std::string& name, const std::string& specialty);

    std::string getName() const;

    std::string getSpecialty() const;

    void printInfo() const;

private:
    Doctor(const std::string& name, const std::string& specialty);
    std::string name;
    std::string specialty;
};