#include "Schedule.h"
#include "Doctor.h"
#include "Patient.h"
#include <chrono>
#include <sstream>

std::shared_ptr<Schedule> Schedule::CreateSchedule(std::chrono::system_clock::time_point workStartTime, std::chrono::system_clock::time_point workEndTime)
{
    return std::shared_ptr<Schedule>(new Schedule(workStartTime, workEndTime));
}

Schedule::Schedule(std::chrono::system_clock::time_point workStartTime, std::chrono::system_clock::time_point workEndTime)
    : workStartTime(workStartTime), workEndTime(workEndTime) {}


void Schedule::AddPatient(const std::shared_ptr<Patient>& patient)
{
    patients.push_back(patient);
    patient->GetSchedule() = shared_from_this();
}

void Schedule::AddDoctor(const std::shared_ptr<Doctor>& doctor)
{
    doctors.push_back(doctor);
    doctor->GetSchedule() = shared_from_this();
}

std::string Schedule::ToString() const
{
    std::stringstream scheduleInfo;

    scheduleInfo << "Рабочее время: "
        << std::chrono::system_clock::to_time_t(workStartTime) << " - "
        << std::chrono::system_clock::to_time_t(workEndTime) << "\n";

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