#include "pch.h"
#include "CppUnitTest.h"
#include "..\Solver\Doctor.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DoctorTest
{
	TEST_CLASS(DoctorTest)
	{
	public:

		TEST_METHOD(Ctor_ValidData_Success)
		{
			std::string name = "Иван";
			std::string specialization = "Кардиолог";
			auto doctor = Doctor::CreateDoctor(name, specialization);
			Assert::AreEqual(doctor->GetName(), name);
			Assert::AreEqual(doctor->GetSpecialization(), specialization);
		}
	};
}
