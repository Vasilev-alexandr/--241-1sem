#include "Schedule.h"
#include "Patient.h"
#include "Doctor.h"
#include <sstream>
#include <iomanip>
#include <ctime>

Schedule::Schedule(std::chrono::system_clock::time_point appointmentTime) : appointmentTime(appointmentTime) {}

std::shared_ptr<Schedule> Schedule::CreateScheduleWithTime(std::chrono::system_clock::time_point appointmentTime)
{
    return std::make_shared<Schedule>(appointmentTime);
}

std::shared_ptr<Schedule> Schedule::CreateSchedule(std::shared_ptr<Doctor> doctor,
    std::shared_ptr<Patient> patient,
    std::chrono::system_clock::time_point appointmentTime)
{
    auto schedule = std::make_shared<Schedule>(appointmentTime);

    schedule->AddDoctor(doctor);
    schedule->AddPatient(patient);

    return schedule;
}

void Schedule::AddDoctor(std::shared_ptr<Doctor> doctor)
{
    this->doctor = doctor;
}

void Schedule::AddPatient(std::shared_ptr<Patient> patient)
{
    this->patient = patient;
}

std::string Schedule::toString() const
{
    std::ostringstream oss;

    auto time = std::chrono::system_clock::to_time_t(appointmentTime);
    std::tm tm = *std::localtime(&time);

    oss << "Расписание для пациента: " << (patient ? patient->getName() : "Неизвестно")
        << " с врачом: " << (doctor ? doctor->getName() : "Неизвестно")
        << " на " << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");

    return oss.str();
}

std::shared_ptr<Doctor> Schedule::getDoctor()
{
    return doctor;
}

std::shared_ptr<Patient> Schedule::getPatient()
{
    return patient;
}
