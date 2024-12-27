#include <gtest/gtest.h>
#include "..//Solver/Doctor.h"
#include "..//Solver/Patient.h"
#include "..//Solver/Schedule.h"

// Тесты для класса Doctor
TEST(DoctorTest, CreateDoctor) {
    auto doctor = Doctor::CreateDoctor("Иванов", "Кардиолог");
    ASSERT_NE(doctor, nullptr);
    EXPECT_EQ(doctor->GetName(), "Иванов");
    EXPECT_EQ(doctor->GetSpecialization(), "Кардиолог");
}

TEST(DoctorTest, ToString) {
    auto doctor = Doctor::CreateDoctor("Иванов", "Кардиолог");
    std::string expected = "Имя доктора: Иванов, Специализация: Кардиолог";
    EXPECT_EQ(doctor->ToString(), expected);
}

// Тесты для класса Patient
TEST(PatientTest, CreatePatient) {
    auto patient = Patient::CreatePatient("Волков", 45);
    ASSERT_NE(patient, nullptr);
    EXPECT_EQ(patient->GetName(), "Волков");
    EXPECT_EQ(patient->GetAge(), 45);
}

TEST(PatientTest, ToString) {
    auto patient = Patient::CreatePatient("Волков", 45);
    std::string expected = "Имя пациента: Волков, Возраст: 45";
    EXPECT_EQ(patient->ToString(), expected);
}

// Тесты для класса Schedule
TEST(ScheduleTest, CreateSchedule) {
    auto startTime = std::chrono::system_clock::now();
    auto endTime = startTime + std::chrono::hours(8);
    auto schedule = Schedule::CreateSchedule(startTime, endTime);
    ASSERT_NE(schedule, nullptr);
}

TEST(ScheduleTest, AddDoctorAndPatient) {
    auto startTime = std::chrono::system_clock::now();
    auto endTime = startTime + std::chrono::hours(8);
    auto schedule = Schedule::CreateSchedule(startTime, endTime);

    auto doctor = Doctor::CreateDoctor("Иванов", "Кардиолог");
    auto patient = Patient::CreatePatient("Волков", 45);

    schedule->AddDoctor(doctor);
    schedule->AddPatient(patient);

    EXPECT_EQ(schedule->ToString(), "Доктор:\nИмя доктора: Иванов, Специализация: Кардиолог\n\nПациент:\nИмя пациента: Волков, Возраст: 45\n");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}