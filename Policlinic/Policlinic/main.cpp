#include <iostream>
#include <memory>
#include "..//Solver/Clinic.h"
#include "..//Solver/Doctor.h"
#include "..//Solver/Patient.h"
#include "..//Solver/Schedule.h"

int main() 
{
    std::setlocale(NULL, "ru_RU.UTF-8");
    Clinic clinic;

    auto schedule1 = std::make_shared<Schedule>("Пн-Пт: 9:00 - 17:00");
    auto schedule2 = std::make_shared<Schedule>("Вт, Чт: 10:00 - 15:00");

    clinic.addDoctor(std::make_shared<Doctor>("Иванов И.И.", "Терапевт", schedule1));
    clinic.addDoctor(std::make_shared<Doctor>("Петров П.П.", "Кардиолог", schedule2));

    clinic.addPatient(std::make_shared<Patient>("Сидоров С.С.", 45));
    clinic.addPatient(std::make_shared<Patient>("Волкова А.А.", 32));

    clinic.listDoctors();

    clinic.listPatients();

    clinic.addAppointmentToPatient("Сидоров С.С.", schedule1);
    clinic.addAppointmentToPatient("Волкова А.А.", schedule2);

    clinic.showPatientAppointments("Сидоров С.С.");

    return 0;
}
