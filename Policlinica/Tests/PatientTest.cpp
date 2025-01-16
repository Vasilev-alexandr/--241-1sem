#include "pch.h"
#include "CppUnitTest.h"
#include "..\Solver\Patient.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PatientTest
{
	TEST_CLASS(PatientTest)
	{
	public:

		TEST_METHOD(Ctor_ValidData_Success)
		{
			std::string name = "Иван";
			int age = 45;
			auto patient = Patient::CreatePatient(name, age);
			Assert::AreEqual(patient->GetName(), name);
			Assert::AreEqual(patient->GetAge(), age);
		}
	};
}
