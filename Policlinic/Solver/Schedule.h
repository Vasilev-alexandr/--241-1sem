#pragma once
#include <string>
#include <iostream>
#include <memory>

class Doctor;
class Patient;

class Schedule final : public std::enable_shared_from_this<Schedule> {
public:

    static std::shared_ptr<Schedule> CreateSchedule(std::shared_ptr<Doctor> doctor, std::shared_ptr<Patient> patient);

    void print() const;

private:
    Schedule(std::shared_ptr<Doctor> doctor, std::shared_ptr<Patient> patient);
    std::shared_ptr<Doctor> doctor;
    std::shared_ptr<Patient> patient;
};