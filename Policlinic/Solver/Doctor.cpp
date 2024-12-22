#include "Doctor.h"
#include "Schedule.h"
#include <iostream>

Doctor::Doctor(const std::string& name, const std::string& specialty) : name(name), specialty(specialty) {}

std::shared_ptr<Doctor> Doctor::CreateDoctor(const std::string& name, const std::string& specialty)
{
    return std::make_shared<Doctor>(name, specialty);
}

std::string Doctor::getName() const
{
    return name;
}
std::string Doctor::getSpecialty() const
{
    return specialty;
}
void Doctor::addSchedule(std::shared_ptr<Schedule> schedule)
{
    schedules.push_back(schedule);
    schedule ->getDoctor() = shared_from_this();
}

std::string Doctor::toString() const
{
    return "Doctor: " + name + ", Specialty: " + specialty;
}
