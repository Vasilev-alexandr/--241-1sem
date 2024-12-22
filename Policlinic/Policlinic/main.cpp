#include <iostream>
#include <memory>
#include <chrono>
#include "..//Solver/Doctor.h"
#include "..//Solver/Patient.h"
#include "..//Solver/Schedule.h"

int main() {
    std::setlocale(LC_ALL, "ru_RU.UTF-8");

    auto doctor1 = Doctor::CreateDoctor("Иванов И.И.", "Терапевт");
    auto doctor2 = Doctor::CreateDoctor("Петров П.П.", "Кардиолог");

    auto patient1 = Patient::CreatePatient("Сидоров С.С.", 45);
    auto patient2 = Patient::CreatePatient("Волкова А.А.", 32);

    auto schedule1 = Schedule::CreateSchedule(doctor1, patient1, std::chrono::system_clock::now());
    auto schedule2 = Schedule::CreateSchedule(doctor2, patient2, std::chrono::system_clock::now() + std::chrono::hours(1));

    std::cout << schedule1->toString() << std::endl;
    std::cout << schedule2->toString() << std::endl;

    std::cout << doctor1->toString() << std::endl;
    std::cout << doctor2->toString() << std::endl;

    std::cout << patient1->toString() << std::endl;
    std::cout << patient2->toString() << std::endl;

    return 0;
}
