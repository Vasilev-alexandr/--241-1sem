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

void Doctor::printInfo() const
{
    std::cout << "Врач: " << name << ", Специальность: " << specialty << std::endl;
    printSchedules();
}

void Doctor::printSchedules() const 
{
    std::cout << "Расписания врача:" << std::endl;
    for (const auto& weakSchedule : schedules)
    {
        if (auto schedule = weakSchedule.lock())
        {
            schedule->print();
        }
        else {
            std::cout << "Расписание больше не существует." << std::endl;
        }
    }
}