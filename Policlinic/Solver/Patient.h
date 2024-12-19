#pragma once
#include <string>
#include <vector>
#include <memory>

class Schedule;

class Patient final : public std::enable_shared_from_this<Patient>{
public:

    static std::shared_ptr<Patient> CreatePatient(const std::string& name, int age);

    std::string getName() const;

    int getAge() const;

    void addAppointment(std::shared_ptr<Schedule> schedule);

    void printInfo() const;

    void printAppointments() const;

private:
    Patient(const std::string& name, int age);
    std::string name;
    int age;
    std::vector<std::shared_ptr<Schedule>> schedules;
};