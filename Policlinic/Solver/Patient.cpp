#include "Patient.h"
#include "Schedule.h"
#include <iostream>

Patient::Patient(const std::string& name, int age) : name(name), age(age) {}


std::shared_ptr<Patient> Patient::CreatePatient(const std::string& name, int age) 
{
    return std::make_shared<Patient>(name, age);
}

std::string Patient::getName() const
{
    return name;
}
int Patient::getAge() const
{
    return age;
}

void Patient::addAppointment(std::shared_ptr<Schedule>& schedule)
{
    schedules.push_back(schedule);
}

void Patient::printInfo() const
{
    std::cout << "Пациент: " << name << ", Возраст: " << age << std::endl;
}

void Patient::printAppointments() const
{
    std::cout << "Записи на прием: " << std::endl;
    for (const auto& weakSchedule : schedules)
    {
        if (auto schedule = weakSchedule.lock())
        {
            schedule->print();
        }
        else
        {
            std::cout << "Расписание больше не существует." << std::endl;
        }
    }
}