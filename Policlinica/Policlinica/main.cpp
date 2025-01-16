#include <iostream>
#include "..\Solver\Schedule.h"
#include "..\\Solver\Patient.h"
#include "..\\Solver\Doctor.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::chrono::system_clock::time_point workStartTime = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point workEndTime = workStartTime + std::chrono::hours(8);

    auto schedule = Schedule::CreateSchedule(workStartTime, workEndTime);

    auto doctor = Doctor::CreateDoctor("Иванов", "Кардиолог");

    auto patient = Patient::CreatePatient("Волков", 45);

    schedule->AddDoctor(doctor);
    schedule->AddPatient(patient);

    std::cout << schedule->ToString() << std::endl;

    return 0;
}