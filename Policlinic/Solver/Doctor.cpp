#include "Doctor.h"

Doctor::Doctor(const std::string& name, const std::string& specialization)
    : name(name), specialization(specialization) {}

std::shared_ptr<Doctor> Doctor::CreateDoctor(const std::string& name, const std::string& specialization)
{
    return std::make_shared<Doctor>(name, specialization);
}

std::string Doctor::ToString() const
{
    return "Врач: " + name + ", Специальность: " + specialization;
}

const std::string& Doctor::GetName() const
{
    return name;
}

const std::string& Doctor::GetSpecialization() const 
{
    return specialization;
}
