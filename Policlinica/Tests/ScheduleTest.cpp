#include "pch.h"
#include "CppUnitTest.h"
#include "..\Solver\Schedule.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ScheduleTest
{
	TEST_CLASS(ScheduleTest)
	{
	public:

		TEST_METHOD(AddPatient_ValidData_Success)
		{
			std::chrono::system_clock::time_point workStartTime = std::chrono::system_clock::now();
			std::chrono::system_clock::time_point workEndTime = workStartTime + std::chrono::hours(8);
			std::string name = "Иван";
			int age = 45;
			auto patient = Patient::CreatePatient(name, age);
			auto schedule = Schedule::CreateSchedule(workStartTime, workEndTime);
			auto result = schedule->AddPatient(patient);
			Assert::IsTrue(result);
		}
		TEST_METHOD(AddDoctor_ValidData_Success)
		{
			std::chrono::system_clock::time_point workStartTime = std::chrono::system_clock::now();
			std::chrono::system_clock::time_point workEndTime = workStartTime + std::chrono::hours(8);
			std::string name = "Иван";
			std::string specialization = "Кардиолог";
			auto doctor = Doctor::CreateDoctor(name, specialization);
			auto schedule = Schedule::CreateSchedule(workStartTime, workEndTime);
			auto result = schedule->AddDoctor(doctor);
			Assert::IsTrue(result);
		}
	};
}
