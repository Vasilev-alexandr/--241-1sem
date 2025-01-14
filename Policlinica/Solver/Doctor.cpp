#include "Doctor.h"
#include <sstream>

Doctor::Doctor(const std::string& name, const std::string& specialization)
    : name(name), specialization(specialization) {}

std::shared_ptr<Doctor> Doctor::CreateDoctor(const std::string& name, const std::string& specialization)
{
    return std::shared_ptr<Doctor>(new Doctor(name, specialization));
}

std::string Doctor::ToString() const
{
    std::stringstream ss;
    ss << "Имя доктора: " << name << ", Специализация: " << specialization;
    return ss.str();
}

const std::string& Doctor::GetName() const
{
    return name;
}

const std::string& Doctor::GetSpecialization() const
{
    return specialization;
}

std::weak_ptr<Schedule> Doctor::GetSchedule() const
{
    return schedule.lock();
}