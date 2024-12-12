#include "Doctor.h"
#include <iostream>

Doctor::Doctor(const std::string& name, const std::string& specialty) : name(name), specialty(specialty) {}

std::string Doctor::getName() const
{
    return name;
}
std::string Doctor::getSpecialty() const
{
    return specialty;
}

void Doctor::printInfo() const 
{
    std::cout << "Врач: " << name << ", Специальность: " << specialty
        << ", Расписание: ";
    schedule->print();
}