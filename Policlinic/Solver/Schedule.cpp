#include "Schedule.h"
#include "Doctor.h"
#include "Patient.h"
#include <chrono>
#include <sstream>
#include <iostream>
#include <stdexcept>

std::shared_ptr<Schedule> Schedule::CreateSchedule(std::chrono::system_clock::time_point workStartTime, std::chrono::system_clock::time_point workEndTime)
{
    return std::shared_ptr<Schedule>(new Schedule(workStartTime, workEndTime));
}

Schedule::Schedule(std::chrono::system_clock::time_point workStartTime, std::chrono::system_clock::time_point workEndTime)
    : workStartTime(workStartTime), workEndTime(workEndTime) {}


void Schedule::AddPatient(const std::shared_ptr<Patient>& patient, const std::chrono::system_clock::time_point& appointmentTime)
{
    if (appointmentTime < workStartTime || appointmentTime > workEndTime)
    {
        throw std::invalid_argument("Прием проводится в нерабочее время врача.");
    }
    patients.push_back(patient);
    patient->schedule = shared_from_this();
}

void Schedule::AddDoctor(const std::shared_ptr<Doctor>& doctor)
{
    doctors.push_back(doctor);
    doctor->schedule = shared_from_this();
}

std::string Schedule::ToString() const 
{
    std::stringstream scheduleInfo;

    scheduleInfo << "Доктор:\n";
    for (const auto& doctor : doctors)
    {
        scheduleInfo << doctor->ToString() << "\n";
    }

    scheduleInfo << "\nПациент:\n";
    for (const auto& patient : patients)
    {
        scheduleInfo << patient->ToString() << "\n";
    }

    return scheduleInfo.str();
}
