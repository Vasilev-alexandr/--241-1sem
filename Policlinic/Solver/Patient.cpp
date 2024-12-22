#include "Patient.h"
#include <sstream>
#include <iomanip>

Patient::Patient(const std::string& name, int age, const std::chrono::system_clock::time_point& appointmentTime)
    : name(name), age(age), appointmentTime(appointmentTime) {}

std::shared_ptr<Patient> Patient::CreatePatient(const std::string& name, int age, const std::chrono::system_clock::time_point& appointmentTime)
{
    return std::make_shared<Patient>(name, age, appointmentTime);
}

std::string Patient::ToString() const
{
    std::ostringstream oss;
    oss << "Пациент: " << name << ", Возраст: " << age
        << ", Время записи: " << GetFormattedAppointmentDate();
    return oss.str();
}

const std::string& Patient::GetName() const
{
    return name;
}

int Patient::GetAge() const
{
    return age;
}

std::chrono::system_clock::time_point Patient::GetAppointmentTime() const
{ 
    return appointmentTime;
}

std::string Patient::GetFormattedAppointmentDate() const
{
    std::time_t time = std::chrono::system_clock::to_time_t(appointmentTime);
    std::tm* tm = std::localtime(&time);
    std::ostringstream oss;
    oss << std::put_time(tm, "%Y-%m-%d %H:%M");
    return oss.str();
}
