#include <iostream>
#include <memory>
#include <locale>
#include "..//Solver/Doctor.h"
#include "..//Solver/Patient.h"
#include "..//Solver/Schedule.h"

int main() {
    std::setlocale(LC_ALL, "ru_RU.UTF-8");

    auto doctor1 = Doctor::CreateDoctor("Иванов И.И.", "Терапевт");
    auto doctor2 = Doctor::CreateDoctor("Петров П.П.", "Кардиолог");

    auto patient1 = Patient::CreatePatient("Сидоров С.С.", 45);
    auto patient2 = Patient::CreatePatient("Волкова А.А.", 32);

    auto schedule1 = std::make_shared<Schedule>(doctor1, patient1);
    auto schedule2 = std::make_shared<Schedule>(doctor2, patient2);

    patient1->addAppointment(schedule1);
    patient2->addAppointment(schedule2);

    std::cout << "Список пациентов:" << std::endl;
    patient1->printInfo();
    patient2->printInfo();

    std::cout << "\nЗаписи пациентов:" << std::endl;
    patient1->printAppointments();
    patient2->printAppointments();

    return 0;
}
