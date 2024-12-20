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

    auto schedule1 = Schedule::CreateSchedule(doctor1, patient1);
    auto schedule2 = Schedule::CreateSchedule(doctor2, patient2);

    std::cout << "Информация о врачах:" << std::endl;
    doctor1->printInfo();
    doctor2->printInfo();

    std::cout << "\nИнформация о пациентах:" << std::endl;
    patient1->printInfo();
    patient2->printInfo();

    std::cout << "\nЗаписи пациентов:" << std::endl;
    patient1->printAppointments();
    patient2->printAppointments();

    return 0;
}
