#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include "..//Solver/Doctor.h"
#include "..//Solver/Patient.h"
#include "..//Solver/Schedule.h"

int main() {
    auto doctor1 = Doctor::CreateDoctor("Иванов", "Кардиолог");
    auto doctor2 = Doctor::CreateDoctor("Волков", "Дерматолог");

    auto patient1 = Patient::CreatePatient("Алина", 30);
    auto patient2 = Patient::CreatePatient("АЛександр", 45);

    auto schedule = Schedule::CreateSchedule();

    auto now = std::chrono::system_clock::now();
    auto workStart1 = now + std::chrono::hours(9);
    auto workEnd1 = workStart1 + std::chrono::hours(8);
    auto workStart2 = now + std::chrono::hours(10);
    auto workEnd2 = workStart2 + std::chrono::hours(6);

    schedule->AddDoctor(doctor1, workStart1, workEnd1);
    schedule->AddDoctor(doctor2, workStart2, workEnd2);

    auto appointment1 = now + std::chrono::hours(3);
    auto appointment2 = now + std::chrono::hours(5);

    schedule->AddPatient(patient1, appointment1);
    schedule->AddPatient(patient2, appointment2);

    schedule->PrintSchedule();

    return 0;
}
