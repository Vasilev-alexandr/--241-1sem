#include "Patient.h"

Patient::Patient(const std::string& name, int age) : name(name), age(age) {}

std::shared_ptr<Patient> Patient::CreatePatient(const std::string& name, int age)
{
    return std::make_shared<Patient>(Patient{ name, age });
}

std::string Patient::ToString() const
{
    std::stringstream ss;
    ss << "Имя пациента: " << name << ", Возраст: " << age;
    return ss.str();
}

const std::string Patient::GetName() const
{
    return name;
}

int Patient::GetAge() const
{
    return age;
}

std::weak_ptr<Schedule>& Patient::GetSchedule()
{
    return schedule;
}

const std::weak_ptr<Schedule>& Patient::GetSchedule() const
{
    return schedule;
}
