#include "Doctor.h"

Doctor::Doctor(const std::string& Name, const std::string& Specialization)
    : name{ Name }, specialization{ Specialization } {}

std::shared_ptr<Doctor> Doctor::CreateDoctor(const std::string& Name, const std::string& Specialization)
{
    return std::make_shared<Doctor>(Doctor{ Name, Specialization });
}

std::string Doctor::ToString() const
{
    std::stringstream ss;
    ss << "Имя доктора: " << name << ", Специализация: " << specialization;
    return ss.str();
}

const std::string Doctor::GetName() const
{
    return name;
}

const std::string Doctor::GetSpecialization() const
{
    return specialization;
}

std::weak_ptr<Schedule>& Doctor::GetSchedule()
{
    return schedule;
}

const std::weak_ptr<Schedule>& Doctor::GetSchedule() const
{
    return schedule;
}
