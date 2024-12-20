#pragma once
#include <string>
#include <memory>
#include <vector>

class Schedule;

class Doctor final : public std::enable_shared_from_this<Doctor> {
public:

    static std::shared_ptr<Doctor> CreateDoctor(const std::string& name, const std::string& specialty);

    std::string getName() const;

    std::string getSpecialty() const;

    void addSchedule(std::shared_ptr<Schedule> schedule);

    void printInfo() const;

    void printSchedules() const;

private:
    Doctor(const std::string& name, const std::string& specialty);
    std::string name;
    std::string specialty;
    std::vector<std::shared_ptr<Schedule>> schedules;
};