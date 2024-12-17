#include "Schedule.h"
#include <iostream>

Schedule::Schedule(std::shared_ptr<Doctor> doctor, std::shared_ptr<Patient> patient) : doctor(doctor), patient(patient) {}

std::shared_ptr<Schedule> Schedule::CreateSchedule(std::shared_ptr<Doctor> doctor, std::shared_ptr<Patient> patient)
{
    return std::make_shared<Schedule>(doctor, patient);
}

void Schedule::print() const
{
    std::cout << "Расписание для пациента: " << patient->getName()
        << " у врача: " << doctor->getName() << std::endl;
}