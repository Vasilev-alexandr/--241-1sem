#include <gtest/gtest.h>
#include "Schedule.h"
#include "..//Solver/Patient.h"
#include "..//Solver/Doctor.h"
#include <chrono>
#include <memory>

class ScheduleTest : public ::testing::Test {
protected:
    void SetUp() override {
        workStartTime = std::chrono::system_clock::now();
        workEndTime = workStartTime + std::chrono::hours(8);

        schedule = std::make_shared<Schedule>(workStartTime, workEndTime);
        doctor = std::make_shared<Doctor>("Иванов", "Кардиолог");
        patient = std::make_shared<Patient>("Волков", 45);
    }

    std::chrono::system_clock::time_point workStartTime;
    std::chrono::system_clock::time_point workEndTime;
    std::shared_ptr<Schedule> schedule;
    std::shared_ptr<Doctor> doctor;
    std::shared_ptr<Patient> patient;
};

TEST_F(ScheduleTest, AddDoctorTest) {
    schedule->AddDoctor(doctor);

    EXPECT_EQ(schedule->ToString().find("Имя доктора: Иванов"), 0);
    EXPECT_EQ(schedule->ToString().find("Специализация: Кардиолог"), 0);
}

TEST_F(ScheduleTest, AddPatientTest) {
    schedule->AddPatient(patient);

    EXPECT_EQ(schedule->ToString().find("Имя пациента: Волков"), 0);
    EXPECT_EQ(schedule->ToString().find("Возраст: 45"), 0);
}

TEST_F(ScheduleTest, ToStringTest) {
    schedule->AddDoctor(doctor);
    schedule->AddPatient(patient);

    std::string scheduleString = schedule->ToString();
    EXPECT_NE(scheduleString.find("Имя доктора: Иванов"), std::string::npos);
    EXPECT_NE(scheduleString.find("Специализация: Кардиолог"), std::string::npos);
    EXPECT_NE(scheduleString.find("Имя пациента: Волков"), std::string::npos);
    EXPECT_NE(scheduleString.find("Возраст: 45"), std::string::npos);
}

TEST(DoctorTest, CreateDoctorTest) {
    auto doctor = Doctor::CreateDoctor("Петров", "Терапевт");

    EXPECT_EQ(doctor->GetName(), "Петров");
    EXPECT_EQ(doctor->GetSpecialization(), "Терапевт");
}

TEST(DoctorTest, ToStringTest) {
    auto doctor = Doctor::CreateDoctor("Петров", "Терапевт");

    EXPECT_EQ(doctor->ToString(), "Имя доктора: Петров, Специализация: Терапевт");
}

TEST(PatientTest, CreatePatientTest) {
    auto patient = Patient::CreatePatient("Смирнов", 30);

    EXPECT_EQ(patient->GetName(), "Смирнов");
    EXPECT_EQ(patient->GetAge(), 30);
}

TEST(PatientTest, ToStringTest) {
    auto patient = Patient::CreatePatient("Смирнов", 30);

    EXPECT_EQ(patient->ToString(), "Имя пациента: Смирнов, Возраст: 30");
}

