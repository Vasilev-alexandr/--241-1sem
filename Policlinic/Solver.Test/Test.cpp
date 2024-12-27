#include <gtest/gtest.h>
#include "..//Solver/Doctor.h"
#include "..//Solver/Patient.h"
#include "..//Solver/Schedule.h"
#include <chrono>

// Тест для создания врача
TEST(DoctorTest, CreateDoctor) {
    auto doctor = Doctor::CreateDoctor("Иванов", "Кардиолог");
    ASSERT_NE(doctor, nullptr);
}

// Тест для метода ToString врача
TEST(DoctorTest, ToString) {
    auto doctor = Doctor::CreateDoctor("Иванов", "Кардиолог");
    std::string doctorInfo = doctor->ToString();
    ASSERT_NE(doctorInfo.find("Имя доктора: Иванов"), std::string::npos);
}

// Тест для создания пациента
TEST(PatientTest, CreatePatient) {
    auto patient = Patient::CreatePatient("Волков", 45);
    ASSERT_NE(patient, nullptr);
}

// Тест для метода ToString пациента
TEST(PatientTest, ToString) {
    auto patient = Patient::CreatePatient("Волков", 45);
    std::string patientInfo = patient->ToString();
    ASSERT_NE(patientInfo.find("Имя пациента: Волков"), std::string::npos);
}

// Тест для создания расписания
TEST(ScheduleTest, CreateSchedule) {
    auto workStartTime = std::chrono::system_clock::now();
    auto workEndTime = workStartTime + std::chrono::hours(8);
    auto schedule = Schedule::CreateSchedule(workStartTime, workEndTime);
    ASSERT_NE(schedule, nullptr);
}

// Тест для добавления врача и пациента в расписание
TEST(ScheduleTest, AddDoctorAndPatient) {
    auto workStartTime = std::chrono::system_clock::now();
    auto workEndTime = workStartTime + std::chrono::hours(8);
    auto schedule = Schedule::CreateSchedule(workStartTime, workEndTime);

    auto doctor = Doctor::CreateDoctor("Иванов", "Кардиолог");
    auto patient = Patient::CreatePatient("Волков", 45);

    schedule->AddDoctor(doctor);
    schedule->AddPatient(patient);

    std::string scheduleInfo = schedule->ToString();
    ASSERT_NE(scheduleInfo.find("Доктор:"), std::string::npos);
}

// Тест для корректности работы с пустым расписанием
TEST(ScheduleTest, EmptySchedule) {
    auto workStartTime = std::chrono::system_clock::now();
    auto workEndTime = workStartTime + std::chrono::hours(8);
    auto schedule = Schedule::CreateSchedule(workStartTime, workEndTime);

    std::string scheduleInfo = schedule->ToString();
    ASSERT_EQ(scheduleInfo.find("Доктор:"), std::string::npos);
}

// Тест для корректного сохранения расписания у врача
TEST(DoctorTest, ScheduleAssignment) {
    auto workStartTime = std::chrono::system_clock::now();
    auto workEndTime = workStartTime + std::chrono::hours(8);
    auto schedule = Schedule::CreateSchedule(workStartTime, workEndTime);

    auto doctor = Doctor::CreateDoctor("Иванов", "Кардиолог");
    schedule->AddDoctor(doctor);

    auto doctorSchedule = doctor->GetSchedule().lock();
    ASSERT_NE(doctorSchedule, nullptr);
}

// Тест для корректного сохранения расписания у пациента
TEST(PatientTest, ScheduleAssignment) {
    auto workStartTime = std::chrono::system_clock::now();
    auto workEndTime = workStartTime + std::chrono::hours(8);
    auto schedule = Schedule::CreateSchedule(workStartTime, workEndTime);

    auto patient = Patient::CreatePatient("Волков", 45);
    schedule->AddPatient(patient);

    auto patientSchedule = patient->GetSchedule().lock();
    ASSERT_NE(patientSchedule, nullptr);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
