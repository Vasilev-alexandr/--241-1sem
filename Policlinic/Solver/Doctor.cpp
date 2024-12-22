#include "Doctor.h"
#include <sstream>
#include <iomanip>

Doctor::Doctor(const std::string& name, const std::string& specialization,
    const std::chrono::system_clock::time_point& workStartTime,
    const std::chrono::system_clock::time_point& workEndTime)
    : name(name), specialization(specialization), workStartTime(workStartTime), workEndTime(workEndTime) {}

std::shared_ptr<Doctor> Doctor::CreateDoctor(const std::string& name, const std::string& specialization,
    const std::chrono::system_clock::time_point& workStartTime,
    const std::chrono::system_clock::time_point& workEndTime)
{
    return std::make_shared<Doctor>(name, specialization, workStartTime, workEndTime);
}

std::string Doctor::ToString() const
{
    std::ostringstream oss;
    oss << "Доктор: " << name << ", Специализация: " << specialization
        << ", Рабочее время: " << GetFormattedWorkStartTime() << " - " << GetFormattedWorkEndTime();
    return oss.str();
}

const std::string& Doctor::GetName() const
{
    return name;
}

const std::string& Doctor::GetSpecialization() const 
{
    return specialization;
}

std::chrono::system_clock::time_point Doctor::GetWorkStartTime() const
{
    return workStartTime;
}

std::chrono::system_clock::time_point Doctor::GetWorkEndTime() const 
{
    return workEndTime;
}

std::string Doctor::GetFormattedWorkStartTime() const
{
    std::time_t time = std::chrono::system_clock::to_time_t(workStartTime);
    std::tm* tm = std::localtime(&time);
    std::ostringstream oss;
    oss << std::put_time(tm, "%H:%M");
    return oss.str();
}

std::string Doctor::GetFormattedWorkEndTime() const
{
    std::time_t time = std::chrono::system_clock::to_time_t(workEndTime);
    std::tm* tm = std::localtime(&time);
    std::ostringstream oss;
    oss << std::put_time(tm, "%H:%M");
    return oss.str();
}
