#include "Schedule.h"
#include <iostream>
#include <sstream>

std::shared_ptr<Schedule> Schedule::CreateSchedule()
{
    return std::make_shared<Schedule>();
}

void Schedule::AddPatient(const std::shared_ptr<Patient>& patient)
{
    patients.push_back(patient);
}

void Schedule::AddDoctor(const std::shared_ptr<Doctor>& doctor)
{
    doctors.push_back(doctor);
}

void Schedule::PrintSchedule() const
{
    std::cout << "Доктора в расписании:\n";
    for (const auto& doctor : doctors)
    {
        std::cout << doctor->ToString() << std::endl;
    }

    std::cout << "\nПациенты в расписании:\n";
    for (const auto& patient : patients)
    {
        std::cout << patient->ToString() << std::endl;
    }
}

std::string Schedule::ToString() const
{
    std::ostringstream oss;
    oss << "Расписание приема:\n";

    for (const auto& doctor : doctors)
    {
        oss << doctor->ToString() << "\n";
    }

    for (const auto& patient : patients)
    {
        oss << patient->ToString() << "\n";
    }

    return oss.str();
}
