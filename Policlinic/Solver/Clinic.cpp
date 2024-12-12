#include "Clinic.h"
#include <iostream>

void Clinic::addDoctor(std::shared_ptr<Doctor> doctor) 
{
    doctors.push_back(doctor);
}

void Clinic::addPatient(std::shared_ptr<Patient> patient)
{
    patients.push_back(patient);
}

void Clinic::listDoctors() const
{
    std::cout << "Список врачей поликлиники:" << std::endl;
    for (const auto& doctor : doctors)
    {
        doctor->printInfo();
    }
}

void Clinic::listPatients() const 
{
    std::cout << "Список пациентов поликлиники:" << std::endl;
    for (const auto& patient : patients)
    {
        patient->printInfo();
    }
}

void Clinic::showPatientAppointments(const std::string& patientName) const
{
    for (const auto& patient : patients)
    {
        if (patient->getName() == patientName)
        {
            patient->printAppointments();
        }
    }
    std::cout << "Пациент с именем " << patientName << " не найден." << std::endl;
}

void Clinic::addAppointmentToPatient(const std::string& patientName, std::shared_ptr<Schedule> schedule) 
{
    for (const auto& patient : patients)
    {
        if (patient->getName() == patientName)
        {
            patient->addAppointment(schedule);
        }
    }
}