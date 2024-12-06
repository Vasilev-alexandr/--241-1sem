#include "Doctor.h"
#include <iostream>

Doctor::Doctor(const std::string& name, const std::string& specialty, const std::string& schedule) : name(name), specialty(specialty), schedule(schedule) {}

std::string Doctor::getName() const
{
    return name;
}
std::string Doctor::getSpecialty() const
{
    return specialty;
}
std::string Doctor::getSchedule() const 
{ 
    return schedule;
}

void Doctor::printInfo() const 
{
    std::cout << "Врач: " << name << ", Специальность: " << specialty << ", Расписание: " << schedule << std::endl;
}