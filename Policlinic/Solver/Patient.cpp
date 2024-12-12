#include "Patient.h"
#include <iostream>

Patient::Patient(const std::string& name, int age) : name(name), age(age) {}

std::string Patient::getName() const
{
    return name;
}
int Patient::getAge() const
{ 
    return age;
}

void Patient::addAppointment(std::shared_ptr<Schedule> appointment)
{
    appointments.push_back(appointment);
}

void Patient::printInfo() const 
{
    std::cout << "Пациент: " << name << ", Возраст: " << age << std::endl;
}

void Patient::printAppointments() const
{
    std::cout << "Записи на прием: " << std::endl;
    for (const auto& appointment : appointments)
    {
        std::cout << " - ";
        appointment->print();
    }
}