#include <iostream>
#include <chrono>
#include <memory>
#include "Schedule.h"
#include "..\\Solver\Patient.h"
#include "..\\Solver\Doctor.h"

int main() {
    std::chrono::system_clock::time_point workStartTime = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point workEndTime = workStartTime + std::chrono::hours(8);

    auto schedule = std::make_shared<Schedule>(workStartTime, workEndTime);

    auto doctor = std::make_shared<Doctor>("Иванов", "Кардиолог");

    auto patient = std::make_shared<Patient>("Волков", 45);

    schedule->AddDoctor(doctor);
    schedule->AddPatient(patient);

    std::cout << schedule->ToString() << std::endl;

    return 0;
}