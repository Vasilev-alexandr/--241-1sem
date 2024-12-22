#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <chrono>
#include <vector>

class Doctor;
class Patient;

class Schedule : public std::enable_shared_from_this<Schedule> {
public:

    static std::shared_ptr<Schedule> CreateSchedule(std::shared_ptr<Doctor> doctor,
        std::shared_ptr<Patient> patient,
        std::chrono::system_clock::time_point appointmentTime);


    static std::shared_ptr<Schedule> CreateScheduleWithTime(std::chrono::system_clock::time_point appointmentTime);

    void AddDoctor(std::shared_ptr<Doctor> doctor);

    void AddPatient(std::shared_ptr<Patient> patient);

    std::string toString() const;

    std::shared_ptr<Doctor> getDoctor();

    std::shared_ptr<Patient> getPatient();


private:
    Schedule(std::chrono::system_clock::time_point appointmentTime);
    std::shared_ptr<Doctor> doctor;
    std::shared_ptr<Patient> patient;
    std::chrono::system_clock::time_point appointmentTime;
};