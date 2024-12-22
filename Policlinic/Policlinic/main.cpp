#include <iostream>
#include "..//Solver/Doctor.h"
#include "..//Solver/Patient.h"
#include "..//Solver/Schedule.h"
#include <chrono>

int main() {
    auto doctor1 = Doctor::CreateDoctor("Доктор Иванов", "Терапевт",
        std::chrono::system_clock::now(),
        std::chrono::system_clock::now() + std::chrono::hours(8));

    auto patient1 = Patient::CreatePatient("Пациент Петров", 30,
        std::chrono::system_clock::now() + std::chrono::hours(1));

    auto schedule = Schedule::CreateSchedule();

    schedule->AddDoctor(doctor1);
    schedule->AddPatient(patient1);

    std::cout << schedule->ToString() << std::endl;

    return 0;
}
