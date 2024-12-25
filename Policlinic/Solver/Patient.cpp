#include "Patient.h"

Patient::Patient(const std::string& name, int age) {}

std::shared_ptr<Patient> Patient::CreatePatient(const std::string& name, int age)
{
    return std::make_shared<Patient>(name, age);
}

std::string Patient::ToString() const
{
    return "Пациент: " + name + ", Возраст: " + std::to_string(age);
}

const std::string& Patient::GetName() const
{
    return name;
}

int Patient::GetAge() const
{
    return age;
}