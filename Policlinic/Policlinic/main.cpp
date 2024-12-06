#include <iostream>
#include <memory>
#include "..//Solver/Clinic.h"
#include "..//Solver/Doctor.h"
#include "..//Solver/Patient.h"

int main() 
{
    std::setlocale(NULL, "ru_RU.UTF-8");
    Clinic clinic;

    clinic.addDoctor(std::make_shared<Doctor>("Иванов И.И.", "Терапевт", "Пн-Пт: 9:00 - 17:00"));
    clinic.addDoctor(std::make_shared<Doctor>("Петров П.П.", "Кардиолог", "Вт, Чт: 10:00 - 15:00"));

    clinic.addPatient(std::make_shared<Patient>("Сидоров С.С.", 45));
    clinic.addPatient(std::make_shared<Patient>("Волкова А.А.", 32));

    clinic.listDoctors();

    clinic.listPatients();

    clinic.addAppointmentToPatient("Сидоров С.С.", "Иванов И.И.");
    clinic.addAppointmentToPatient("Волкова А.А.", "Петров П.П.");

    clinic.showPatientAppointments("Сидоров С.С.");

    return 0;
}
