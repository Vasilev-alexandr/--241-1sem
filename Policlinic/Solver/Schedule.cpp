#include "Schedule.h"
#include <iomanip>
#include <sstream>

std::shared_ptr<Schedule> Schedule::CreateSchedule()
{
    return std::make_shared<Schedule>();
}

void Schedule::AddPatient(const std::shared_ptr<Patient>& patient,
    const std::chrono::system_clock::time_point& appointmentTime)
{
    patientSchedules.push_back({ patient, appointmentTime });
    patient->schedule = shared_from_this();
}

void Schedule::AddDoctor(const std::shared_ptr<Doctor>& doctor,
    const std::chrono::system_clock::time_point& workStartTime,
    const std::chrono::system_clock::time_point& workEndTime)
{
    doctorSchedules.push_back({ doctor, workStartTime, workEndTime });
    doctor->schedule = shared_from_this();
}

void Schedule::PrintSchedule() const
{
    for (const auto& schedule : doctorSchedules) {
        std::time_t start_time = std::chrono::system_clock::to_time_t(schedule.workStartTime);
        std::time_t end_time = std::chrono::system_clock::to_time_t(schedule.workEndTime);
        std::cout << schedule.doctor->ToString() << ", Начало работы: "
            << std::put_time(std::localtime(&start_time), "%H:%M") << " - "
            << std::put_time(std::localtime(&end_time), "%H:%M") << std::endl;
    }

    for (const auto& schedule : patientSchedules) {
        std::time_t appointment_time = std::chrono::system_clock::to_time_t(schedule.appointmentTime);
        std::cout << schedule.patient->ToString() << ", Расписание: "
            << std::put_time(std::localtime(&appointment_time), "%d-%m-%Y %H:%M") << std::endl;
    }
}

std::string Schedule::ToString() const
{
    std::ostringstream oss;
    for (const auto& schedule : doctorSchedules) {
        std::time_t start_time = std::chrono::system_clock::to_time_t(schedule.workStartTime);
        std::time_t end_time = std::chrono::system_clock::to_time_t(schedule.workEndTime);
        oss << schedule.doctor->ToString() << ", Начало работы: "
            << std::put_time(std::localtime(&start_time), "%H:%M") << " - "
            << std::put_time(std::localtime(&end_time), "%H:%M") << std::endl;
    }

    for (const auto& schedule : patientSchedules) {
        std::time_t appointment_time = std::chrono::system_clock::to_time_t(schedule.appointmentTime);
        oss << schedule.patient->ToString() << ", Расписание: "
            << std::put_time(std::localtime(&appointment_time), "%d-%m-%Y %H:%M") << std::endl;
    }
    return oss.str();
}
