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
    schedule->getPatient() = shared_from_this();
}

std::string Patient::toString() const
{
    return "Patient: " + name + ", Age: " + std::to_string(age);
}