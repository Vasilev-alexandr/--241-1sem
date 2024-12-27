#include <iostream>
#include <chrono>
#include "..//Solver/Doctor.h"
#include "..//Solver/Patient.h"
#include "..//Solver/Schedule.h"

int main() {
    std::chrono::system_clock::time_point workStartTime = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point workEndTime = workStartTime + std::chrono::hours(8);
    
    auto schedule = Schedule::CreateSchedule(workStartTime, workEndTime);

    auto doctor = Doctor::CreateDoctor("Иванов", "Кардиолог");

    auto patient = Patient::CreatePatient("Волков", 45);

    schedule->AddDoctor(doctor);
    schedule->AddPatient(patient, workStartTime + std::chrono::hours(2));

    std::cout << schedule->ToString() << std::endl;

    return 0;
}
