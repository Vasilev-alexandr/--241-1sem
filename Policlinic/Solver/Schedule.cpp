#include "Schedule.h"
#include "Doctor.h"
#include "Patient.h"
#include <iostream>

Schedule::Schedule(std::shared_ptr<Doctor> doctor, std::shared_ptr<Patient> patient) : doctor(doctor), patient(patient) {}

std::shared_ptr<Schedule> Schedule::CreateSchedule(std::shared_ptr<Doctor> doctor, std::shared_ptr<Patient> patient)
{
    auto schedule = std::make_shared<Schedule>(doctor, patient);

    doctor->addSchedule(schedule);
    patient->addAppointment(schedule);

    return schedule;

}

void Schedule::print() const
{
    std::cout << "Расписание для пациента: " << patient->getName()
        << " у врача: " << doctor->getName() << std::endl;
}

std::shared_ptr<Doctor> Schedule::getDoctor()
{
    return doctor;
}

std::shared_ptr<Patient> Schedule::getPatient()
{
    return patient;
}
